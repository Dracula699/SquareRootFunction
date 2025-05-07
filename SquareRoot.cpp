// Gusys my name is SAI THAKARE and I just wanted to create my own Square root function and this is what I came up with <__>

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int countDigits(int n) {
    if (n == 0)
        return 1;
    return static_cast<int>(std::floor(std::log10(std::abs(n))) + 1);
}

std::string odd_even (int digits) {
    if (digits % 2 == 0) {
        return "Even";
    }
    else  {
        return "Odd";
    }
}

struct square{
    double square_root;
    double square;
};
square nearest_square_to_n(double n, std::string odd_r_even, double count_of_digits) {
    square output;
    int x;
    int y;
    
    // Your original range determination logic
    if(odd_r_even == "Even") {
        x = count_of_digits/2;
        if (x == 1) {
            x = 1;
            y = 9;
        }
        else  {
            y = pow(10, x) - 1;
            x = pow(10, x-1);
        }
    }
    else {
        x = (count_of_digits+1)/2; 
        if (x == 1) {
            x = 1;
            y = 9;
        }
        else  {
            y = pow(10, x) - 1;
            x = pow(10, x-1);
        }
    }

    int starting_point = x, ending_point = y;
    int best_root = x;
    long long min_diff = abs(x*x - n);
    
    while (starting_point <= ending_point) {
        int middle_point = (starting_point + ending_point) / 2;
        long long current_sq = middle_point * middle_point;
        long long current_diff = abs(current_sq - n);

        if (current_diff < min_diff) {
            min_diff = current_diff;
            best_root = middle_point;
        }
  
        if (current_sq == n) {
            best_root = middle_point;
            break;
        }
        else if (current_sq > n) {
            ending_point = middle_point - 1;
        }
        else {
            starting_point = middle_point + 1;
        }
    }
    
    output.square = best_root * best_root;
    output.square_root = best_root;
    return output;
}

double square_root_function(double nearest_number, double n, double square_root_nearestnumber) {
    double square;
    double diff;
    if (nearest_number > n) {
        diff = nearest_number - n;
        square = square_root_nearestnumber - diff/nearest_number * 2;
    }
    else {
        diff = n - nearest_number;
        square = square_root_nearestnumber + diff/nearest_number * 2;
    }
    return square;
}


int main () {
    int n;
    cout << "Pelase enter a number: ";
    cin >> n;
    int digitcount = countDigits(n);
    std::string odd_or_even = odd_even(digitcount);
    square nearest_number = nearest_square_to_n(n, odd_or_even, digitcount);
    
    double output = square_root_function(nearest_number.square, n, nearest_number.square_root);
    cout << "The square root of the number: " << n << " is " << output;
    return 0;
}

