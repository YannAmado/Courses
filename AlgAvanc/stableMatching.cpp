//
// Created by Yann on 27/08/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>


typedef struct person{
    int name;
    std::vector<int> pref;
    int fiance;
}person_t;


person_t* choose_prefs(int n_marriages){
    //+1 so the number of the person matches with de array index
    int person;
    std::vector<int> prefs;
    person_t* person_array = (person_t*)malloc((n_marriages+1)*sizeof(person_t));
    for(int i = 0; i < n_marriages; i++){
        person_array[i+1].name = i+1;
        person_array[i+1].fiance = 0;
        //the first index is what person, the next are that persons prefs
        scanf(" %d", &person);
        for(int j = 0; j < n_marriages; j++){
            scanf(" %d", &person);
            prefs.push_back(person);
        }
        person_array[i+1].pref = prefs;
        prefs.clear();
    }
    return person_array;
}

void free_mem(person_t* man, person_t* woman){
    free(man);
    free(woman);
}


void partner_up(person_t* man, person_t* woman, int m, int w){
    man[m].fiance = w;
    woman[w].fiance = m;
    for(int i = 0; i < (int)(man[m].pref.size()); i++){
        if(man[m].pref[i] == w) {
            man[m].pref.erase(man[m].pref.begin() + i);
            return;
        }
    }
}

std::vector<person_t>  remove_from_singles(std::vector<person_t> m_singles, int current_m){
    for(int j = 0; j < (int)(m_singles.size()); j++){
        if(m_singles[j].name == current_m){
            m_singles.erase(m_singles.begin() + j);
            return m_singles;
        }
    }
    return m_singles;
}

std::vector<person_t>  find_partner(int current_m, person_t* man, person_t* woman, std::vector<person_t> m_singles
                  , int n_marriages){
    int desired_w, w_fiance;
    //The for below will iterate through all of the male remaining preferences
    for(int i = 0; i < (int)(man[current_m].pref.size()); i++){
        desired_w = man[current_m].pref[0];
        w_fiance = woman[desired_w].fiance;

        //the mans current preference will either be taken by him or someone else
        //either way, he will never have the possibility of being with her again :(
        man[current_m].pref.erase(man[current_m].pref.begin());

        //if the woman is single
        if(woman[desired_w].fiance == 0){
            partner_up(man, woman, current_m, desired_w);
            m_singles = remove_from_singles(m_singles, current_m);
            return m_singles;
        }

        for(int j = 0; j < n_marriages; j++){
            //if she prefers her fiance
            if(woman[desired_w].pref[j] == w_fiance)
                break;
            //if she prefers the new man
            if(woman[desired_w].pref[j] == current_m){
                partner_up(man, woman, current_m, desired_w);
                m_singles = remove_from_singles(m_singles, current_m);
                //making her ex fiance single
                man[w_fiance].fiance = 0;
                m_singles.push_back(man[w_fiance]);
                return m_singles;
            }
        }
    }
    return m_singles;
}

void print_marriages(person_t* man, int n_marriages){
    for(int i = 0; i < n_marriages; i++)
        printf("%d %d\n", man[i+1].name, man[i+1].fiance);
}

int main(){
    int n_test, n_marriages;
    person_t* man = NULL;
    person_t* woman= NULL;
    std::vector<person_t> m_singles;
    scanf("%d", &n_test);
    for(int n = 0; n < n_test; n++){
        scanf("%d", &n_marriages);
        woman = choose_prefs(n_marriages);
        man = choose_prefs(n_marriages);
        for(int i = 0; i < n_marriages; i++){
            m_singles.push_back(man[i+1]);
        }
        int current_m = 1;
        while(m_singles.size() > 0 && man[current_m].pref.size() > 0){
            current_m = m_singles[0].name;
            m_singles = find_partner(current_m, man, woman, m_singles,  n_marriages);
        }
        print_marriages(man, n_marriages);
        free_mem(man, woman);
        m_singles.clear();
    }
    return 0;
}