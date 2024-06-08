#include "utility.h"
#include "List.h"
#include "main.h"

int main(){
   clock_t start, finish;
   double elapsed_time;

   bool exit_now = false;
   List<Personal_record> record_list;

   string user_input;

   while(!exit_now){
      cout << endl;
      cout << "***********************" << endl;
      cout << "Menu:" << endl;
      cout << "1. Import List from File" << endl;
      cout << "2. Display List" << endl;
      cout << "3. Search List" << endl;
      cout << "x. Exit" << endl;
      cout << "***********************" << endl;

      getline(cin, user_input);

      if(user_input == "1"){
         string input;
         cout << endl << "Enter Data File Name:" << endl;
         getline(cin, input);
         ifstream insertion_file;
         insertion_file.open(input.c_str());
         if(!insertion_file.fail()){
            record_list.clear();

            Personal_record input_rec;
            string code_string;
            while (getline(insertion_file, input_rec.last_name) && getline(insertion_file, input_rec.first_name) && getline(insertion_file, code_string)) {
               input_rec.last_name = rtrim(input_rec.last_name);
               input_rec.first_name = rtrim(input_rec.first_name);
               input_rec.code = string_to_int(code_string);
                            
                bool insert = true;
                for(int i = 0; i < record_list.size(); i++){
                    Personal_record current;
                    record_list.retrieve(i, current);
                    if(current.last_name == input_rec.last_name && current.first_name == input_rec.first_name){
                        insert = false;
                        break; // Duplicate found, do not insert
                    }
                }

                if(insert){
                    int i = 0;
                    Personal_record current;
                    while(i < record_list.size() && 
                          (record_list.retrieve(i, current), 
                          current.last_name < input_rec.last_name ||
                          (current.last_name == input_rec.last_name && current.first_name < input_rec.first_name))){
                        i++;
                    }
                    record_list.insert(i, input_rec);
                }
            }
         } else
            cout << "Invalid file name." << endl;
      }
      else if(user_input == "2"){
         if (record_list.size() == 0)
         { 
            cout << "List empty";
            continue;
         }
         for(int i = 0; i < record_list.size(); i++)
         {
            Personal_record pr;
            record_list.retrieve(i, pr);

            cout << "Last Name:" << pr.last_name << endl;
            cout << "First Name:" << pr.first_name << endl;
            cout << "Code:" << pr.code << endl;
         }
      }
      else if(user_input == "3"){
         if (record_list.size() == 0)
         { 
            cout << "List empty";
            continue;
         }
         string search_first_name, search_last_name;
         cout << endl;
         cout << "Enter the last name to search:" << endl;
         getline(cin, search_last_name);
         cout << endl;
         cout << "Enter the first name to search:" << endl;
         getline(cin, search_first_name);
         start = clock();

         bool found = false;
         for (int i = 0; i < record_list.size(); i++) {
             Personal_record pr;
             record_list.retrieve(i, pr);
             if (pr.last_name == search_last_name && pr.first_name == search_first_name) {
                 cout << "Last Name: " << pr.last_name << endl;
                 cout << "First Name: " << pr.first_name << endl;
                 cout << "Code: " << pr.code << endl;
                 found = true;
                 break;
             }
         }
         if (!found) {
             cout << "Not found." << endl;
         }

         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      } 
      else if(user_input == "x")
         exit_now = true;
   }
}

