library(shiny)
library(dplyr)
library(ggplot2)

pokemon <- read.csv("pokemon.csv", encoding="UTF-8", stringsAsFactors = FALSE)

ui <- fluidPage(
  titlePanel("Pokemon: Find best opponenent in a fight"),
  sidebarLayout(
    sidebarPanel(
      textInput('textInput', 'Enter a Pokemon name (with capital letter)'),
      actionButton("searchButton", "Search"),
      br(),br(),
      selectInput("nameInput", "Pokemon name (preselected examples)",
                  choices = c("Pikachu", "Charmander", "Bulbasaur", "Squirtle")),
      sliderInput("damageRange", "Damage Range", min = 0, max = 1000,
                  value = c(200, 800))
    ),
    mainPanel(
      plotOutput("coolplot"),
      br(), br(),
      tableOutput("results")
    )
  )
)

server <- function(input, output) {
  
  is_outlier <- function(v, coef=0.7){
    quantiles <- quantile(v,probs=c(0.25,0.75))
    IQR <- quantiles[2]-quantiles[1]
    res <- v < (quantiles[1]-coef*IQR)|v > (quantiles[2]+coef*IQR)
    return(res)
  }
  
  type1 <- reactive({
    pokemon[pokemon$name == input$nameInput, ]$type1
  })
  
  againstName <- function (name) {
    as.name(paste("against_", tolower(name), sep=""))
  }
  
  getBestSpecial <- reactive({
    pokemon %>%
      mutate(damage = !!againstName(type1()) * attack) %>%
      filter(damage > input$damageRange[1]) %>%
      filter(damage < input$damageRange[2]) %>%
      mutate(label=ifelse(is_outlier(damage), name, ""))
  })
  
  getBestSpecial2 <- reactive({
    pokemon %>%
      mutate(damage = !!againstName(pokemon[pokemon$name == input$textInput, ]$type1) * attack) %>%
      filter(damage > input$damageRange[1]) %>%
      filter(damage < input$damageRange[2]) %>%
      mutate(label=ifelse(is_outlier(damage), name, ""))
  })
  
  my_theme <- theme_grey() + theme(legend.key = element_rect(fill=NA),
                                   axis.text = element_text(size=14),
                                   axis.title = element_text(size=16,face="bold"),
                                   legend.text = element_text(size = 14),
                                   legend.title = element_text(size = 16,face="bold"),
                                   legend.position = "right",
                                   panel.grid.major.x = element_blank(),
                                   strip.text = element_text(size = 15),
                                   plot.title = element_text(size = 14, face="bold"))
  
  poke_colors <- c("#A6B91A",
                   "#705746",
                   "#6F35FC",
                   "#F7D02C",
                   "#D685AD",
                   "#C22E28",
                   "#EE8130",
                   "#A98FF3",
                   "#735797",
                   "#7AC74C",
                   "#E2BF65",
                   "#96D9D6",
                   "#A8A77A",
                   "#A33EA1",
                   "#F95587",
                   "#B6A136",
                   "#B7B7CE",
                   "#6390F0")
  
  observeEvent(input$nameInput, {
    output$coolplot <- renderPlot({
      x <- as.name("name")
      y <- as.name("damage")
      dat <- getBestSpecial()
      
      ggplot(dat, aes(x=defense, y=damage, label=label, size=speed, color=type1)) +
        geom_point(alpha = 0.8, shape = 19) + 
        geom_text(aes(label=label), hjust=-0.1, vjust=-0.1) +
        my_theme +
        scale_color_manual(values = poke_colors, name= "Pokemon Type") +
        scale_size_continuous(name="Attack Speed") +
        xlab("Defense points") + ylab("Damage Score") +
        ggtitle("Best opponents")
    })
  })
  
  observeEvent(input$searchButton, {
    output$coolplot <- renderPlot({
      x <- as.name("name")
      y <- as.name("damage")
      dat <- getBestSpecial2()
      
      ggplot(dat, aes(x=defense, y=damage, label=label, size=speed, color=type1)) +
        geom_point(alpha = 0.8, shape = 19) + 
        geom_text(aes(label=label), hjust=-0.1, vjust=-0.1) +
        my_theme +
        scale_color_manual(values = poke_colors, name= "Pokemon Type") +
        scale_size_continuous(name="Attack Speed") +
        xlab("Defense points") + ylab("Damage Score") +
        ggtitle("Best opponents")
    })
  })

}


shinyApp(ui = ui, server = server)