#!/usr/bin/bash

# This script checks if an input date is valid or not
# Usage: ./datecheck.sh <month> <date> <year>
# Example: ./datecheck.sh 1 2 2016
# Example: ./datecheck.sh 11 2 2017
# Example: ./datecheck.sh Nov 2 2017

# Checking if the number of arguments is correct
if [ $# -ne 3 ]; then
    echo "Usage: $0 month day year"
    exit 1
fi

monthName=''

# Checking if the month is valid
case $1 in
    jan|Jan|JAN|01)
        month=1
        monthName='Jan'
        ;;
    feb|Feb|FEB|02)
        month=2
        monthName='Feb'
        ;;
    mar|Mar|MAR|03)
        month=3
        monthName='Mar'
        ;;
    apr|Apr|APR|04)
        month=4
        monthName='Apr'
        ;;
    may|May|MAY|05)
        month=5
        monthName='May'
        ;;
    jun|Jun|JUN|06)
        month=6
        monthName='Jun'
        ;;
    jul|Jul|JUL|07)
        month=7
        monthName='Jul'
        ;;
    aug|Aug|AUG|08)
        month=8
        monthName='Aug'
        ;;
    sep|Sep|SEP|09)
        month=9
        monthName='Sep'
        ;;
    oct|Oct|OCT|10)
        month=10
        monthName='Oct'
        ;;
    nov|Nov|NOV|11)
        month=11
        monthName='Nov'
        ;;
    dec|Dec|DEC|12)
        month=12
        monthName='Dec'
        ;;
    *)
        echo "BAD INPUT: $1 is not a valid month."
        exit 1
        ;;
esac

# Checking if the day is valid, will throw error if less than 1
if [ $2 -lt 1 ]; then
    echo "BAD INPUT: $monthName does not have $2 days."
    exit 1
fi

# Checking if the year is valid, will throw error if less than 1
if [ $3 -lt 1 ]; then
    echo "BAD INPUT: $3 is not a valid year."
    exit 1
fi

# Checking if the day is valid for the given month, will throw error if greater than the days in the respective month
case $month in

    1|3|5|7|8|10|12)
    # Checking for Jan, Mar, May, Jul, Aug, Oct, Dec
        if [ $2 -gt 31 ]; then
            echo "BAD INPUT: $monthName does not have $2 days."
            exit 1
        fi
        ;;
    4|6|9|11)
    # Checking for Apr, Jun, Sep, Nov
        if [ $2 -gt 30 ]; then
            echo "BAD INPUT: $monthName does not have $2 days."
            exit 1
        fi
        ;;
    2)
    # Checking for Feb
        if [ $3 -eq 0 ]; then
            echo "BAD INPUT: $monthName $3 does not have $2 days."
            exit 1
        fi

        # logic layout for funding leap year is below:
        
        # if year is divisible by 4 and not divisible by 100 & 400, then it is a leap year
        # if year is divisible by 100 but not 400, then it is not a leap year
        # if year is divisible by 100 and 400, then it is a leap year
        # if year is not divisible by 4, then it is not a leap year

        if [ $(( $3 % 4 )) -eq 0 ]; then
            if [ $(( $3 % 100 )) -eq 0 ]; then
                if [ $(( $3 % 400 )) -eq 0 ]; then
                    if [ $2 -gt 29 ]; then
                        echo "BAD INPUT: $monthName $3 does not have $2 days: not a leap year."
                        exit 1
                    fi
                else
                    if [ $2 -gt 28 ]; then
                        echo "BAD INPUT: $monthName $3 does not have $2 days: not a leap year."
                        exit 1
                    fi
                fi
            else
                if [ $2 -gt 29 ]; then
                    echo "BAD INPUT: $monthName $3 does not have $2 days: not a leap year."
                    exit 1
                fi
            fi
        else
            if [ $2 -gt 28 ]; then
                echo "BAD INPUT: $monthName $3 does not have $2 days: not a leap year."
                exit 1
            fi
        fi
        ;;
esac

# If the script reaches this point, the date is valid
echo "EXISTS! $monthName $2 $3 is someone's birthday."
