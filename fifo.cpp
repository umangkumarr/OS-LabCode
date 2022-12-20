#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Number of entries: ";
    cin >> n;

    vector<vector<int> > data(n, vector<int>(3));
    cout << "Process\t Aval. Time \t Burst Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> data[i][0];
        cin >> data[i][1];

        data[i][2] = i + 1;
    }
    cout << "\n\n";

    // sort by avalaible time
    sort(data.begin(), data.end());

    int time = 0;
    double total_waiting_time = 0;
    double total_turnaround_time = 0;

    cout << "Process Description:\n";
    cout << "Process\t\tAval. T.\tBurst T.\tWaiting T.\tTurnaround T.\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << data[i][2] << "\t\t";
        cout << data[i][0] << "\t\t";
        cout << data[i][1] << "\t\t";

        // update time
        time = max(time, data[i][0]);

        // print waiting and Turnaround time
        cout << time - data[i][0] << "\t\t";
        cout << time - data[i][0] + data[i][1] << "\t\t";

        // add to total waiting time and turnaround time
        total_waiting_time += time - data[i][0];
        total_turnaround_time += time - data[i][0] + data[i][1];

        // update time
        time += data[i][1];
        cout << "\n";
    }

    cout << "\n";
    cout << "Average Waiting Time: " << total_waiting_time / n << "\n";
    cout << "Average Turnaround Time: " << total_turnaround_time / n << "\n";
}