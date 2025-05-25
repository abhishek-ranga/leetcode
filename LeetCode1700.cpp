class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q; stack<int> st;
        for(int i=0; i<students.size(); i++) q.push(students[i]);
        for(int i=sandwiches.size()-1; i>=0; i--) st.push(sandwiches[i]);
        int pNp = 0;
        while(pNp!=q.size()){
            if(q.front()==st.top()){
                pNp = 0;
                q.pop();
                st.pop();
            }
            else{
                pNp++;
                q.push(q.front());
                q.pop();
            }
        }
        return q.size();
    }
};