#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    static const int Jobs_Count = 4;
    cout << "Total number of jobs: " << Jobs_Count << endl;
    vector< vector<int> > job_info(Jobs_Count,vector<int>(7));
    int start_t = 0, end_t = 0, clock_t = 0, run = 0;
    int hrrn_pr[Jobs_Count] = {0};
// Generating Process_ID
    for (int row = 0, col = 0; row < Jobs_Count; row++)
    {
        job_info[row][col] = row + 1;
    }

// Generating arrival time
    for (int row = 0, col = 1; row < Jobs_Count; row++)
    {
        if (row == 0)
            job_info[row][col] = row;
        else
            job_info[row][col] = row + 2;
    }

// Generating burst time
    for (int row = 0, col = 2; row < Jobs_Count; row++)
    {
        job_info[row][col] =  rand() % 10 + 2 ;
    }

    cout << endl << "List of Process number" << endl;
    for (int i = 0; i < Jobs_Count; i++)
    {
        cout << job_info[i][0] << " ";
    }
    cout << endl << "Arrival time" << endl;
    for (int i = 0; i < Jobs_Count; i++)
    {
        cout << job_info[i][1] << " ";
    }
    cout << endl <<  "Burst time" << endl;
    for (int i = 0; i < Jobs_Count; i++)
    {
        cout << job_info[i][2] << " ";
    }
    cout << endl <<  "Jobs hrrn priority" << endl;
    for (int i = 0; i < Jobs_Count; i++)
    {
        cout << hrrn_pr[i] << " ";
    }



// CPU HRRN scheduling begins
// for the first job, completion time is arrival time + burst time
    clock_t = job_info[0][1] + job_info[0][2];
    job_info[0][3] = clock_t;
    end_t = clock_t;
// HRRN job priority calculation


    for ( run = 1; run < Jobs_Count; run++)
    {
        calc_hrrn;
    }

    return 0;
}
