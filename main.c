#include <stdio.h>
#include "budget_lib.h"
#include "input_utils.h"
#include "file_io.h"

typedef enum
{
    STATE_MAIN_MENU,
    STATE_ADD_RECORD,
    STATE_SHOW_ALL,
    STATE_CALC_SUMMARY,
    STATE_SAVE_FILE,
    STATE_LOAD_FILE,
    STATE_EXIT
} AppState;

AppState run_main_menu(void);

int main(void)
{
    Record_t records[MAX_RECORDS];
    int record_count = 0;
    AppState state = STATE_MAIN_MENU;

    while(state != STATE_EXIT)
    {
        switch(state)
        {
            case STATE_MAIN_MENU:
                state = run_main_menu();
                break;

            case STATE_ADD_RECORD:
            {
                char desc[DESC_LEN];
                float amount;
                int type;
                printf("\n==== Add New Record ====\n");
                if(!read_string("Enter description: ", desc, DESC_LEN))
                {
                    printf("Invalid input.\n");
                    state = STATE_MAIN_MENU;
                    break;
                }
                if(!read_float("Enter amount: ", &amount) || amount <= 0)
                {
                    printf("Amount must be positive number.\n");
                    state = STATE_MAIN_MENU;
                    break;
                }
                if(!read_int("Type 1=Income, 0=Expense: ", &type) || (type !=0 && type !=1))
                {
                    printf("Please enter 0 or 1.\n");
                    state = STATE_MAIN_MENU;
                    break;
                }
                int ok = budget_add_record(records, &record_count, desc, amount, type);
                if(!ok)
                {
                    printf("Record storage full! Cannot add.\n");
                }
                else
                {
                    printf("Record added successfully.\n");
                }
                state = STATE_MAIN_MENU;
                break;
            }

            case STATE_SHOW_ALL:
            {
                printf("\n==== All Records ====\n");
                if(record_count == 0)
                {
                    printf("No records stored.\n");
                }
                for(int i=0; i<record_count; i++)
                {
                    printf("[%d] %s | %.2f | %s\n",
                           i, records[i].desc, records[i].amount,
                           records[i].is_income ? "INCOME" : "EXPENSE");
                }
                state = STATE_MAIN_MENU;
                break;
            }

            case STATE_CALC_SUMMARY:
            {
                float inc, exp, bal;
                budget_get_summary(records, record_count, &inc, &exp, &bal);
                printf("\n==== Summary Report ====\n");
                printf("Total Income:  %.2f\n", inc);
                printf("Total Expense: %.2f\n", exp);
                printf("Current Balance: %.2f\n", bal);
                state = STATE_MAIN_MENU;
                break;
            }

            case STATE_SAVE_FILE:
            {
                char fname[64];
                read_string("Enter output filename(e.g budget.txt): ", fname, sizeof(fname));
                if(save_records_to_file(fname, records, record_count))
                {
                    printf("Saved to file OK.\n");
                }
                else
                {
                    printf("Failed to open file for writing.\n");
                }
                state = STATE_MAIN_MENU;
                break;
            }

            case STATE_LOAD_FILE:
            {
                char fname[64];
                read_string("Enter file name to load: ", fname, sizeof(fname));
                if(load_records_from_file(fname, records, &record_count))
                {
                    printf("Loaded records from file.\n");
                }
                else
                {
                    printf("Cannot open file.\n");
                }
                state = STATE_MAIN_MENU;
                break;
            }

            case STATE_EXIT:
                break;
            default:
                printf("Unknown state, return menu.\n");
                state = STATE_MAIN_MENU;
                break;
        }
    }
    printf("Program exiting.\n");
    return 0;
}

AppState run_main_menu(void)
{
    int sel;
    printf("\n==== CLI Budget Tracker ====\n");
    printf("1. Add new record\n");
    printf("2. Show all records\n");
    printf("3. Show finance summary\n");
    printf("4. Save records to file\n");
    printf("5. Load records from file\n");
    printf("6. Exit\n");
    if(!read_int("Please select option: ", &sel))
    {
        printf("Bad input, please enter menu number.\n");
        return STATE_MAIN_MENU;
    }
    switch(sel)
    {
        case 1: return STATE_ADD_RECORD;
        case 2: return STATE_SHOW_ALL;
        case 3: return STATE_CALC_SUMMARY;
        case 4: return STATE_SAVE_FILE;
        case 5: return STATE_LOAD_FILE;
        case 6: return STATE_EXIT;
        default:
            printf("Invalid menu choice.\n");
            return STATE_MAIN_MENU;
    }
}
