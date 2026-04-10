#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Process {
    int pid, at, bt, ct, wt, tat;
};

// ----------- Print Table + Average -----------
void print(vector<Process> p) {
    float avgWT = 0, avgTAT = 0;

    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto pr : p) {
        cout << pr.pid << "\t" << pr.at << "\t" << pr.bt << "\t"
             << pr.ct << "\t" << pr.tat << "\t" << pr.wt << "\n";
        avgWT += pr.wt;
        avgTAT += pr.tat;
    }

    cout << "Average WT = " << avgWT / p.size() << endl;
    cout << "Average TAT = " << avgTAT / p.size() << endl;
}

// ----------- FCFS -----------
void fcfs(vector<Process> p) {
    cout << "\n--- FCFS ---\n";

    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    int time = 0;
    cout << "Gantt: ";

    for (auto &pr : p) {
        if (time < pr.at) time = pr.at;

        cout << time << " |P" << pr.pid << "| ";
        time += pr.bt;

        pr.ct = time;
        pr.tat = pr.ct - pr.at;
        pr.wt = pr.tat - pr.bt;
    }
    cout << time << endl;

    print(p);
}

// ----------- SJF (Non-Preemptive) -----------
void sjf(vector<Process> p) {
    cout << "\n--- SJF (Non-Preemptive) ---\n";

    int n = p.size(), time = 0, completed = 0;
    vector<bool> done(n, false);

    cout << "Gantt: ";

    while (completed < n) {
        int idx = -1, min_bt = 1e9;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        cout << time << " |P" << p[idx].pid << "| ";
        time += p[idx].bt;

        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        done[idx] = true;
        completed++;
    }
    cout << time << endl;

    print(p);
}

// ----------- SRTF (Preemptive SJF) -----------
void srtf(vector<Process> p) {
    cout << "\n--- SRTF (Preemptive SJF) ---\n";

    int n = p.size();
    vector<int> rem(n);

    for (int i = 0; i < n; i++) rem[i] = p[i].bt;

    int time = 0, completed = 0;

    cout << "Gantt: ";

    while (completed < n) {
        int idx = -1, min_bt = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && rem[i] > 0 && rem[i] < min_bt) {
                min_bt = rem[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        cout << time << " |P" << p[idx].pid << "| ";
        rem[idx]--;
        time++;

        if (rem[idx] == 0) {
            completed++;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }
    }
    cout << time << endl;

    print(p);
}

// ----------- Round Robin -----------
void roundRobin(vector<Process> p, int q) {
    cout << "\n--- Round Robin ---\n";

    int n = p.size();
    vector<int> rem(n);

    for (int i = 0; i < n; i++) rem[i] = p[i].bt;

    queue<int> ready;
    vector<bool> inQ(n, false);

    int time = 0;
    ready.push(0);
    inQ[0] = true;

    cout << "Gantt: ";

    while (!ready.empty()) {
        int i = ready.front();
        ready.pop();

        cout << time << " |P" << p[i].pid << "| ";

        int exec = min(q, rem[i]);
        time += exec;
        rem[i] -= exec;

        for (int j = 0; j < n; j++) {
            if (p[j].at <= time && !inQ[j] && rem[j] > 0) {
                ready.push(j);
                inQ[j] = true;
            }
        }

        if (rem[i] > 0) {
            ready.push(i);
        } else {
            p[i].ct = time;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
    }
    cout << time << endl;

    print(p);
}

// ----------- MAIN -----------
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter AT and BT for P" << i + 1 << ": ";
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
    }

    fcfs(p);
    sjf(p);
    srtf(p);

    int quantum;
    cout << "\nEnter Time Quantum: ";
    cin >> quantum;

    roundRobin(p, quantum);

    return 0;
}