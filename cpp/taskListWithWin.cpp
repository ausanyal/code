#include <iostream>

using namespace std;

#define NUM_TASKS 3

int runTasks(int *tl, int n, int win) {
    int lastRun[NUM_TASKS+1];
    memset(lastRun, -1, sizeof(lastRun));
    for (int i = 0; i < n; i++) {
        int n1 = tl[i];
        if ((lastRun[n1] == -1) || ((i - (lastRun[n1])) >= win )) {
            lastRun[n1] = i;
            cout << tl[i] << " ";
        } else {
            cout << "- ";
        }
    }
    return 0;
}

int runTasks2(int *tl, int n, int win) {
    int lastRun[NUM_TASKS+1];
    memset(lastRun, -1, sizeof(lastRun));
    int curr = 0, i = 0;
    while (i < n) {
        int n1 = tl[i];
        if (n1 == -1) { 
            i++;
            continue;
        }
        if ((lastRun[n1] == -1) || ((i - (lastRun[n1])) >= win )) {
            lastRun[n1] = i;
            curr++;
            i++;
            cout << n1 << " ";
        } else {
            int j;
            for (j = i+1; j < n; j++) {
                int n2 = tl[j];
                if (n2 == -1) continue;
                if ((lastRun[n2] == -1) || ((curr - (lastRun[n2])) >= win )) {
                    lastRun[n2] = j;
                    curr++;
                    i = curr;
                    tl[j] = -1;
                    cout << n2 << " ";
                    break;
                }
            }
            if (j == n) { 
                cout << "- ";
                curr++;
                i = curr;
            }
        }
    }
    return 0;
}

int main()
{
    int taskList[] = {1, 2, 1, 2, 1, 1, 1, 3, 2, 2, 1, 2, 3, 1, 2, 3};
    runTasks(taskList, sizeof(taskList)/sizeof(taskList[0]), 3);
    cout << endl;
    runTasks2(taskList, sizeof(taskList)/sizeof(taskList[0]), 3);
    cout << endl;
    return 0;
}

#if 0
int runTasks2(int *tl, int n, int win) {
    int lastRun[NUM_TASKS+1];
    memset(lastRun, -1, sizeof(lastRun));
    int curr = 0;
    for (int i = 0; i < n; i++) {
        cout << endl << "\t\t\ti:" << i << " val:" << tl[i] << " curr:" << curr 
             << " lastRun:" << lastRun[tl[i]] << endl;
        if (tl[i] == -1) continue;
        int n1 = tl[i];
        if ((lastRun[n1] == -1) || ((curr - (lastRun[n1])) >= win )) {
            lastRun[n1] = i;
            cout << tl[i] << " ";
            tl[i] = -1;
            curr++;
        } else {
            int j;
            for (j = i+1; j < n; j++) {
                cout << endl << "\t\t\ti:" << i << " j:" << j << " val:" << tl[j] << " curr:" << curr 
                     << " lastRun:" << lastRun[tl[j]] << endl;
                if (tl[j] == -1) continue;
                int n2 = tl[j];
                if ((lastRun[n2] == -1) || ((curr - (lastRun[n2])) >= win )) {
                    tl[j] = -1;
                    lastRun[n2] = i;
                    cout << "\n\t\t\tusing j: " << j << endl;
                    cout << n2 << " ";
                    curr++;
                    //cout << endl << " i:" << i << " j:" << j << " n2:" << n2 
                    //     << " lastRun[n2]:" << lastRun[n2] << endl;
                    //return 0;
                    break;
                } 
            }
            if (j == n) cout << "- ";
        }
    }
    return 0;
}
#endif
