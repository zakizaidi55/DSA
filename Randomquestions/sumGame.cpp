class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSideQuestionMark = 0;
        int rightSideQuestionMark = 0;
        int leftSideSum = 0;
        int rightSideSum = 0;

        for(int i=0; i<n; i++) {
            if(num[i] == '?') {
                if(i < n/2) {
                    // left side
                    leftSideQuestionMark++;
                }

                else {
                    // right side
                    rightSideQuestionMark++;
                }
            }

            else {
                if(i < n/2) {
                    leftSideSum += num[i] - '0';
                }

                else {
                    rightSideSum += num[i] - '0';
                }
            }
        }


        if((leftSideQuestionMark + rightSideQuestionMark)%2 == 1) {
            // iska matlab mere pass odd time questions marks hai
            // it means harr baar alice hi jitegi, kyuki wo sum ko maximise kar degi
            return true;
        }

        // important point: yha matlab hai ki mere pass left se kitna total sum bann sakta h, or right se total kitna sum bann sakta hai wo nikal rahe h
        int left = 2*leftSideSum + 9*leftSideQuestionMark;
        int right = 2*rightSideSum + 9*rightSideQuestionMark;

        if(left == right)
            return false;

        return true;
    }
};
