// main.cpp
//  a2_q2.cpp
//
//  Created by Laura Persichini on 2020-10-10.
//  Copyright © 2020 Laura Persichini. All rights reserved.
//
/*

 Project: Distance computation (question #2)
 Purpose: Compute the distance travelled by a ball over a set time interval/ time it takes to travel a set distance.
 Due date: October 11, 2020
 */
//
/*
 To test the program logic, I used easy test values, such as 0 and 1. This proved to be useful as it allowed me to
 compare the output from the program with the chart given in the question and identify any issues with the code. Furthermore, I used
 the online calculator to verify that my calculations were correct. For the second part of the question, I used to the online
 calculator to ensure that the the program was outputting the correct result for the time that the ball was hitting the ground at.
 The program outputs that the ball will hit the ground between 55.30 seconds and 55.40 seconds. The online calculator computed
 that the ball will hit the ground at 55.3095 seconds.
 */
//
//  Created by Laura Persichini on 2020-10-05.
//  Copyright © 2020 Laura Persichini. All rights reserved.
//

#include <iostream>
#include <iomanip> // used for formatting the output chart
using namespace std;

// using the formula distance = 0.5 * g * t^2
// using g = 9.80665
//total distance formula
double total_distance(double t) {
    double g = 9.80665;
    double dist_total = 0.5 * g * t * t;
    return dist_total;
}

// returns the distance between two time intervals with a given time (t) and resolution
double distance_interval(double t, double resolution) {
    double interval_dist = total_distance(t) - total_distance(t - resolution);
    if (interval_dist < 0) {
        return 0.000;
    } else {
        return interval_dist;
    }
}

// outputs all distances and distance intervals between 0-52 seconds with a resolution of 1 second
void output_distance () {
    for (int i = 0; i <= 52; i++) {
        cout << fixed << setprecision(3) << i << setw(40) << distance_interval(i,1) << setw(40) << total_distance(i) << endl;
    }
}

//outputs all distances and distance intervals between 53-56 seconds with a resolution of 0.1 second
void output_distance_highresolution () {
    for (double i = 53; i <= 56; i+= 0.1) {
        cout << fixed << setprecision(3) <<  i << setw(36) << distance_interval(i,0.1) << setw(40) << total_distance(i) << endl;
    }
}

// main function
int main(int argc, const char * argv[]) {
    // printing the headers of the output chart
    cout << "time (in sec):" << setw(40) << "distance during interval (in m):" << setw(30) << "total distance (in m):" << endl;
    output_distance();
    output_distance_highresolution();
    
    return 0;
}
