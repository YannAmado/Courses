package external;

import org.knowm.xchart.SwingWrapper;
import org.knowm.xchart.XYChart;
import org.knowm.xchart.XYChartBuilder;
import org.knowm.xchart.XYSeries.XYSeriesRenderStyle;

public class Plot {
	private static int width = 600;
	private static int height = 500;
	private static String type = "Linear";
	
	public Plot(int graph_width, int graph_height) {
		width = graph_width;
		height = graph_height;
	}
	
	public static void setWidth(int graph_width) {
		width = graph_width;
	}
	
	public static void setHeight(int graph_height) {
		height = graph_height;
	}
	
	private static void plotChart(String title, String legenda, double x_data[], double y_data[]) {
			// Create Chart
			XYChart chart = new XYChartBuilder().width(width).height(height).title(title).xAxisTitle("X").yAxisTitle("Y").build();
			chart.addSeries(legenda, x_data, y_data);
	
			if(type.equals("Linear"))
				chart.getStyler().setDefaultSeriesRenderStyle(XYSeriesRenderStyle.Line);
			else if(type.equals("Scatter"))
				chart.getStyler().setDefaultSeriesRenderStyle(XYSeriesRenderStyle.Scatter);
			else if(type.equals("Area")) 
				chart.getStyler().setDefaultSeriesRenderStyle(XYSeriesRenderStyle.Area);
			// Show it
			new SwingWrapper<XYChart>(chart).displayChart();
		
	}

	public static void plotChart(String title, String legenda, double y_data[]){
		// Create Chart
		int array_size = y_data.length;
		double[] x_data = new double[array_size];  
		for(int i = 0; i < array_size; i++) {
			x_data[i] = (double)(i+1);
		}
		Plot.plotChart(title, legenda, x_data, y_data);
		
	}
	public static void plotChart(String title, String legenda, int x_data[], int y_data[]){
		// Create Chart
		int array_size = y_data.length;
		double[] dy_data = new double[array_size];
		double[] dx_data = new double[array_size];  
		for(int i = 0; i < array_size; i++) {
			dx_data[i] = (double)x_data[i];
			dy_data[i] = (double)y_data[i];
	
		}
		Plot.plotChart(title, legenda, dx_data, dy_data);
		
	}
	
	public static void plotChart(String title, String legenda, int y_data[]){
		// Create Chart
		int array_size = y_data.length;
		double[] dy_data = new double[array_size];
		double[] x_data = new double[array_size];  
		for(int i = 0; i < array_size; i++) {
			x_data[i] = (double)(i+1);
			dy_data[i] = (double)y_data[i];
		}
		Plot.plotChart(title, legenda, x_data, dy_data);
		
	}
	
	public static void plotLinearChart(String title, String legenda, double x_data[], double y_data[]){
		// Create Chart
		type = "Linear";
		Plot.plotChart(title, legenda, x_data, y_data);
	}

	public static void plotLinearChart(String title, String legenda, double y_data[]){
		// Create Chart
		type = "Linear";
		Plot.plotChart(title, legenda, y_data);
	}
	
	public static void plotLinearChart(String title, String legenda, int x_data[], int y_data[]){
		// Create Chart
		type = "Linear";
		Plot.plotChart(title, legenda, x_data, y_data);
		
	}
	
	public static void plotLinearChart(String title, String legenda, int y_data[]){
		// Create Chart
		type = "Linear";
		Plot.plotChart(title, legenda, y_data);
	}
	
	public static void plotScatterChart(String title, String legenda, double x_data[], double y_data[]) {
		// Create Chart
		type = "Scatter";
		Plot.plotChart(title, legenda, x_data, y_data);
	}
	
	public static void plotScatterChart(String title, String legenda, double y_data[]) {
		type = "Scatter";
		// Show it
		Plot.plotChart(title, legenda, y_data);
	}
	
	public static void plotScatterChart(String title, String legenda, int x_data[], int y_data[]){
		// Create Chart
		type = "Scatter";
		Plot.plotChart(title, legenda, x_data, y_data);
		
	}
	
	public static void plotScatterChart(String title, String legenda, int y_data[]){
		type = "Scatter";
		Plot.plotChart(title, legenda, y_data);
	}
	
	public static void plotAreaChart(String title, String legenda, double x_data[], double y_data[]) {
		// Create Chart
		type = "Area";
		Plot.plotChart(title, legenda, x_data, y_data);
	}
	
	public static void plotAreaChart(String title, String legenda, double y_data[]) {
		type = "Area";
		// Show it
		Plot.plotChart(title, legenda, y_data);
	}
	
	public static void plotAreaChart(String title, String legenda, int x_data[], int y_data[]){
		// Create Chart
		type = "Area";
		Plot.plotChart(title, legenda, x_data, y_data);
		
	}
	
	public static void plotAreaChart(String title, String legenda, int y_data[]){
		type = "Area";
		Plot.plotChart(title, legenda, y_data);
	}
	
}