#include <iostream>
#include "HRRN.h"
#include <cstdlib>
#include <vector>
//#include <ctime>
using namespace std;

static const int Jobs_Count = 4;
vector< vector<int> > job_info(Jobs_Count,vector<int>(7));
int start_t = 0, end_t = 0, clock_t = 0, run = 0;
int hrrn_pr[Jobs_Count] = {0};
int jid =0, pri_rity =0;

void cal_jid();
void cal_hrrn();
void cal_CT();
void show_hrrn();

int main()
{

    cout << "Hello world!" << endl;
    cout << "Total number of jobs: " << Jobs_Count << endl;
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
    /*cout << endl <<  "Jobs hrrn priority" << endl;
    for (int i = 0; i < Jobs_Count; i++)
    {
        cout << hrrn_pr[i] << " ";
    }*/

// CPU HRRN scheduling begins
// for the first job, completion time is arrival time + burst time
 /*   clock_t = job_info[0][1] + job_info[0][2];
    job_info[0][3] = clock_t;
    end_t = clock_t;*/
    cal_CT();

    cout << endl << "end time for first job " << end_t;
// HRRN job priority calculation
    cout << "\nlast job arrival time " << job_info[Jobs_Count-1][1] << endl;

    cal_jid();
    cout << endl << "jid " << jid;
    cal_hrrn();
    show_hrrn();
    cout << "\n run " << run << endl;
    if (jid <= (Jobs_Count/2))
    {
        run++;
        cal_CT();
    }
    cout << endl << " 2nd end time for first job " << end_t;
    cal_jid();
    cout << endl << "2nd jid " << jid;
    //reset_hrrn();
    cal_hrrn();
    show_hrrn();
   // reset_hrrn();


    return 0;
}

    void cal_jid()
    {
       //for ( int k = Jobs_Count - 1; (k > 0 && (job_info[k][1] > end_t)); k--){
       //    jid = k;        }
        for ( int k = run+1; k < (Jobs_Count); k++)
        {
            if (job_info[k][1] <= end_t)
                jid = k;
        }
    }

    void cal_hrrn()
    {
        for ( int i = (run + 1), prepri = 0, pri = 0; i <= jid; i++)
        {
           job_info[i][6] = ((end_t - job_info[i][1]) + job_info[i][2])/job_info[i][2];
        }
    }
    void cal_CT()
    {
        job_info[run][3] = end_t + job_info[run][2];
        end_t = job_info[run][3];
    }

    void show_hrrn()
    {
        cout << endl <<  "Jobs hrrn priority" << endl;
        for (int i = 0; i < Jobs_Count; i++)
        {
            cout << job_info[i][6] << " ";
        }
    }
