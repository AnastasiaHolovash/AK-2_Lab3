#include <cstdio>
#include <cstring>
#include <getopt.h>
#include <cstdlib>


int main(int argc, char *argv[]) {

    int getopt;

    const char *short_options = "hvo::l:";

    const struct option long_options[] = {
            {"help",    no_argument,       NULL, 'h'},
            {"version", no_argument,       NULL, 'v'},
            {"one",     optional_argument, NULL, 'o'},
            {"list",    required_argument, NULL, 'l'},
            {NULL, 0,                      NULL, 0}
    };

    int option_index;

    bool h_used = false, v_used = false, l_used = false, o_used = false;

    const char *arguments_msg = "You can use:\n"
                                "-h               or --help               - get help\n"
                                "-v               or --version            - get version of the program\n"
                                "-o[one argument] or --one=[one argument] - set number if with args, get number if without\n"
                                "-l[<arg1>,...]   or --list=[<arg>,...]   - input list\n";


    while ((getopt = getopt_long(argc, argv, short_options,
                              long_options, &option_index)) != -1) {

        switch (getopt) {
            case 'h': {
                if (!h_used) {
                    printf("**\n%s**\n", arguments_msg);
                    h_used = true;
                }
                break;
            }
            case 'v': {
                if (!v_used) {
                    printf("** Version **\n");
                    v_used = true;
                }
                break;
            }
            case 'o': {
                if (!o_used) {
                    if (optarg != NULL) {
                        char *convert;
                        double entered = strtod(optarg, &convert);
                        if (entered != 0) {
                            printf("** Your number: %.1f **\n", entered);
                        } else {
                            printf("** Error: Wrong input!!! **\n");
                        }
                    } else {
                        printf("** This is one: %.1f **\n", 1.0);
                    }
                    o_used = true;
                }
                break;
            }
            case 'l': {
                if (!l_used) {
                    printf("** List: ");
                    char *entered = strtok(optarg, ",");
                    while (entered != NULL) {
                        printf("%s, ", entered);
                        entered = strtok(NULL, ",");
                    }
                    printf("**\n");
                    l_used = true;
                }
                break;
            }
            case '?':
            default: {
                printf("Wrong argument. To see the list of arguments use -h or --help.\n");
                break;
            }
        }
    }
    return 0;
}
