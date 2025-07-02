//Program build for converting between the different units of temperature and distance respectively.
#include <stdio.h> //Includes the std input and output library.
#include <stdlib.h> //Includes functions for dynamic memory, program termination, general-purpose functions.
#include <ctype.h> //Includes functions for character handling, such as checking character types (e.g., alphabetic, numeric).
#include <string.h> //Includes functions for string manipulation, including string length, copying and comparison.
#include <stdbool.h> //Includes the bool data constants true and false.

//Checks for the input that it matches the given requirements
bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line){
    bool format_is_correct = num_args_read == num_args_needed;
    if(should_be_last_value_on_line){
        char should_be_newline = '?';
        scanf("%c", &should_be_newline);
        format_is_correct = format_is_correct && should_be_newline == '\n';
    }
    return format_is_correct;
}

//Takes a valid double input from the user and format validation.
double getValidDouble(const bool isLastElementOnLine) {
    const int numArgsNeeded = 1;
    int numArgsRead;
    double num;

    numArgsRead = scanf(" %lf", &num);
    if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
        return num;
    } else {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}


//Takes a valid character from user input and format validation.
char getValidChar(const bool isLastElementOnLine) {
    const int numArgsNeeded = 1;
    int numArgsRead;
    char theCharacter;

    numArgsRead = scanf(" %c", &theCharacter);
    if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
        return theCharacter;
    } else {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

//Function for conversion of units between different units of temperature.
// It converts Kelvin, Celsius and Fahrenheit into each other.
double temperature_converter(double value, double from_unit, char to_unit) {
    double result = 0.0;
    if (from_unit == 'F' || from_unit == 'f') {
        if (to_unit == 'C' || to_unit == 'c') {
            result = (value - 32) * 5/9;
        } else if (to_unit == 'K' || to_unit == 'k') {
            result = (value - 32) * 5/9 + 273.15;
        } else if (to_unit == 'F' || to_unit == 'f') {
            result = value;
        }
    }else if (from_unit == 'C' || from_unit == 'c') {
        if (to_unit == 'F' || to_unit == 'f') {
            result = (value * 9/5) + 32;
        } else if (to_unit == 'K' || to_unit == 'k') {
            result = value + 273.15;
        }else if (to_unit == 'C' || to_unit == 'c') {
            result = value;
        }
    }else if (from_unit == 'K' || from_unit == 'k') {
        if (to_unit == 'F' || to_unit == 'f') {
            result = (value - 273.15) * 9 / 5 + 32;
        } else if (to_unit == 'C' || to_unit == 'c') {
            result = value - 273.15;
        } else if (to_unit == 'K' || to_unit == 'k') {
            result = value;
        }
    }else {
        exit(0);
    }
    return result;
}

//Function for conversion of units between different units of distance.
// It converts Miles, yards, Inches and feets into each other.
double Dist_Convertor(double value, char from_unit, char to_unit) {
    double result = 0.0;

    if (from_unit == 'I' || from_unit == 'i') {
        if (to_unit == 'F' || to_unit == 'f') {
            result = value / 12.0; // Inches to Feet
        } else if (to_unit == 'Y' || to_unit == 'y') {
            result = value / 36.0; // Inches to Yards
        } else if (to_unit == 'M' || to_unit == 'm') {
            result = value / 63360.0; // Inches to Miles
        } else if (to_unit == 'I' || to_unit == 'i') {
            result = value; // Inches to Inches
        }
    } else if (from_unit == 'F' || from_unit == 'f') {
        if (to_unit == 'I' || to_unit == 'i') {
            result = value * 12.0; // Feet to Inches
        } else if (to_unit == 'Y' || to_unit == 'y') {
            result = value / 3.0; // Feet to Yards
        } else if (to_unit == 'M' || to_unit == 'm') {
            result = value / 5280.0; // Feet to Miles
        } else if (to_unit == 'F' || to_unit == 'f') {
            result = value; // Feet to Feet
        }
    } else if (from_unit == 'Y' || from_unit == 'y') {
        if (to_unit == 'I' || to_unit == 'i') {
            result = value * 36.0; // Yards to Inches
        } else if (to_unit == 'F' || to_unit == 'f') {
            result = value * 3.0; // Yards to Feet
        } else if (to_unit == 'M' || to_unit == 'm') {
            result = value / 1760.0; // Yards to Miles
        } else if (to_unit == 'Y' || to_unit == 'y') {
            result = value; // Yards to Yards
        }
    } else if (from_unit == 'M' || from_unit == 'm') {
        if (to_unit == 'I' || to_unit == 'i') {
            result = value * 63360.0; // Miles to Inches
        } else if (to_unit == 'F' || to_unit == 'f') {
            result = value * 5280.0; // Miles to Feet
        } else if (to_unit == 'Y' || to_unit == 'y') {
            result = value * 1760.0; // Miles to Yards
        } else if (to_unit == 'M' || to_unit == 'm') {
            result = value; // Miles to Miles
        }
    } else {
        exit(0);
    }
    return result;
}

//Takes input from the user.
//Guides inputs from the user to different functions.
//Recall temperature_converter for temperature conversions.
//Recall distance_converter for distance conversion.
//End program whenever the user inputs wrong values or conversion types.
int main(void) {
    char type;
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    type = getValidChar(true);

    if (type == 't' || type == 'T') {
        double temp, result1; ;
        char fromunit, tounit;

        printf("Enter the temperature followed by its suffix (F,C, or K): ");
        temp = getValidDouble(false);
        fromunit = getValidChar(true);

        if (fromunit == 'F' || fromunit == 'C' || fromunit == 'K' || fromunit == 'f' || fromunit == 'c' || fromunit == 'k') {
            printf("Enter the new unit type (F, C, or K): ");
            tounit = getValidChar(true);
            if (tounit == 'F' || tounit == 'C' || tounit == 'K' || tounit == 'f' || tounit == 'c' || tounit == 'k'){
                result1 = temperature_converter(temp, fromunit, tounit);
                printf("%.2lf%c is %.2lf%c", temp, toupper(fromunit), result1, toupper(tounit));
            } else {//Ends program when wrong unit is inputted by user.
                printf("%c is not a valid temperature type. Ending program.", toupper(tounit));
                exit(0);// Use exit(0) to terminate the program with an error code.
            }
        }
        else {// End program whenever user inputs wrong conversion type.
            printf("%c is not a valid temperature type. Ending program.", toupper(fromunit));
            exit(0);// Use exit(0) to terminate the program with an error code.
        }
    }

    else if (type == 'D' || type == 'd') {
        double dist, result2;
        char FromUnit, ToUnit;;
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");
        dist = getValidDouble(false);
        FromUnit = getValidChar(true);

        if (FromUnit == 'I' || FromUnit == 'F' || FromUnit == 'Y' || FromUnit == 'M' || FromUnit == 'i' || FromUnit == 'f' || FromUnit == 'y' || FromUnit == 'm') {
            printf("Enter the new unit type (I,F,Y,M): ");
            ToUnit = getValidChar(true);
            if (ToUnit == 'I' || ToUnit == 'F' || ToUnit == 'Y' || ToUnit == 'M' || ToUnit == 'i' || ToUnit == 'f' || ToUnit == 'y' || ToUnit == 'm'){
                result2 = Dist_Convertor(dist, FromUnit, ToUnit);
                printf("%.2lf%c is %.2lf%c", dist, toupper(FromUnit), result2, toupper(ToUnit));
            } else {
                printf("%c is not a valid distance type. Ending program.", toupper(ToUnit));
                exit(0);// Use exit(0) to terminate the program with an error code.
            }
        }
        else {//Ends program when wrong unit is inputted by user.
            printf("%c is not a valid distance type. Ending program.", toupper(FromUnit));
            exit(0);// Use exit(0) to terminate the program with an error code.
        }
    }

    else { // End program whenever user inputs wrong conversion type.
        printf("Unknown conversion type %c chosen. Ending program.", toupper(type));
        exit(0); // Use exit(0) to terminate the program with an error code.
    }

    return 0;
}
