/* 7. Write a program which is used to pint home directory & login user name. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *home_dir;
    char *login_name;

    // Get the home directory
    home_dir = getenv("HOME");

    if (home_dir == NULL) {
        printf("Unable to retrieve home directory\n");
        return 1;
    }

    // Get the login username
    login_name = getenv("USER");

    if (login_name == NULL) 
    {
        printf("Unable to retrieve login username\n");
        return 1;
    }

    printf("Home directory: %s\n", home_dir);
    printf("Login username: %s\n", login_name);

    return 0;
}
