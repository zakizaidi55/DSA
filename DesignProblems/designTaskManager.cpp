class TaskManager {
public:
    unordered_map<int, int>taskPriorityMap; // task -> priority
    unordered_map<int, int>taskOwnerMap; // task -> owner
    priority_queue<pair<int, int > > maxHeap; // priority, task
    TaskManager(vector<vector<int>>& tasks) {
        for(auto&task: tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskPriorityMap[taskId] = priority;
        taskOwnerMap[taskId] = userId;
        maxHeap.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        // isme bas hum maxHeap m new entry dalege and baad m taskPriorityMap ki help se validate karlege
        maxHeap.push({newPriority, taskId});
        // humne map m task k related new priority daldi hai
        taskPriorityMap[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskPriorityMap[taskId] = -1;
    }
    
    int execTop() {
        while(!maxHeap.empty()) {
            // yeh hum tab tak chalayege, jab tak humko sahi entry nhi mil jati
            auto top = maxHeap.top();
            int priority = top.first;
            int task = top.second;

            // ab hum taskPriorityMap m check karege ki yeh entry sahi h ya nhi
            if(taskPriorityMap[task] == priority) {
                taskPriorityMap[task] = -1;
                return taskOwnerMap[task];
            }

            maxHeap.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */


