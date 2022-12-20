#include <bits/stdc++.h>
using namespace std;

// fetch next job
int findNextJob(vector<int> done, vector<vector<int>> data, int n, int time) {
    // find the job which has already arrived and has minimum burst time
    for (int i = 0; i < n; i++) {
        if (find(done.begin(), done.end(), data[i][2]) == done.end()) {
            if (time >= data[i][1]) return data[i][2];
        }
    }

    // find job which will arrive first but have not arrived yet
    int indx = -1;
    int aval_time = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (find(done.begin(), done.end(), data[i][2]) == done.end()) {
            if (aval_time > data[i][1]) {
                aval_time = data[i][1];
                indx = data[i][2];
            }
        }
    }

    // return id of the process/Job
    return indx;
}

int main() {
    cout << "Enter no. of Process: ";
    int n;
    cin >> n;

    vector<int> done;
    vector<vector<int>> data(n, vector<int>(3));

    cout << "Process\t Aval. Time \t Burst Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> data[i][1] >> data[i][0];
        data[i][2] = i;
    }
    cout << "\n\n";

    // sort by burst time
    sort(data.begin(), data.end());

    int time = 0;
    double total_waiting_time = 0;
    double total_turnaround_time = 0;

    int cnt = 0;
    cout << "Process Description:\n";
    cout << "Process\t\tAval. T.\tBurst T.\tWaiting T.\tTurnaround T.\n";
    while (cnt < n) {
        // find next job
        int indx = findNextJob(done, data, n, time);

        // find the index of next job
        int j;
        for (int i = 0; i < n; i++) {
            if (data[i][2] == indx) {
                j = i;
            }
        }

        // print details
        time = max(time, data[j][1]);
        cout << "P" << data[j][2] + 1 << "\t\t";
        cout << data[j][1] << "\t\t";
        cout << data[j][0] << "\t\t";

        cout << time - data[j][1] << "\t\t";
        cout << time - data[j][1] + data[j][0] << "\t\t";

        // add current job waiting time to total waiting time and turnaround
        // time
        total_waiting_time += time - data[j][1];
        total_turnaround_time += time - data[j][1] + data[j][0];
        time += data[j][0];
        cout << "\n";

        cnt++;
        done.push_back(indx);
    }

    cout << "\n";
    cout << "Average Waiting Time: " << total_waiting_time / n << "\n";
    cout << "Average Turnaround Time: " << total_turnaround_time / n << "\n";
}


// Enter no. of Process: 5
// Process  Aval. Time      Burst Time
// P1: 2 6
// P2: 5 2
// P3: 1 8
// P4: 0 3
// P5: 4 4


// Process Description:
// Process         Aval. T.        Burst T.        Waiting T.      Turnaround T.
// P4              0               3               0               3
// P1              2               6               1               7
// P2              5               2               4               6
// P5              4               4               7               11
// P3              1               8               14              22

// Average Waiting Time: 5.2
// Average Turnaround Time: 9.8