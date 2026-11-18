#include <stdio.h>
#include "budget_lib.h"
#include "input_utils.h"

int main(void)
{
    AppState state = STATE_MENU;
    Transaction records[MAX_RECORDS];
    int record_count = 0;
    int choice;

    while (state != STATE_EXIT)
    {
        switch (state)
        {
            case STATE_MENU:
                printf("\n===== Budget Tracker =====\n");
                printf("1. Add new record\n");
                printf("2. View all records & balance\n");
                printf("3. Save records to file\n");
                printf("4. Load records from file\n");
                printf("5. Exit\n");
                printf("Please enter your choice: ");
                if (!read_int(&choice))
                {
                    printf("Invalid input!\n");
                    state = STATE_MENU;
                    break;
                }

                switch (choice)
                {
                    case 1: state = STATE_ADD_RECORD; break;
                    case 2: state = STATE_VIEW_RECORDS; break;
                    case 3: state = STATE_SAVE; break;
                    case 4: state = STATE_LOAD; break;
                    case 5: state = STATE_EXIT; break;
                    default:
                        printf("Invalid option, back to menu.\n");
                        state = STATE_MENU;
                        break;
                }
                break;

            case STATE_ADD_RECORD:
                add_record(records, &record_count);
                state = STATE_MENU;
                break;
            case STATE_VIEW_RECORDS:
                view_records(records, record_count);
                state = STATE_MENU;
                break;
            case STATE_SAVE:
                save_records("records.txt", records, record_count);
                state = STATE_MENU;
                break;
            case STATE_LOAD:
                load_records("records.txt", records, &record_count);
                state = STATE_MENU;
                break;
            case STATE_EXIT:
                printf("Program exit.\n");
                break;
            default:
                state = STATE_MENU;
                break;
        }
    }
    return 0;
}
