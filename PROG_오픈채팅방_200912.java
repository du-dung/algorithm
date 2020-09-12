/* 오픈채팅방 Level 2
https://programmers.co.kr/learn/courses/30/lessons/42888
*/
import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        // 유저의 정보, key는 id, value는 닉네임
        Map<String, String> users = new HashMap<String, String>();

        // 최종 닉네임 찾기 & 채팅방 길이 찾기
        StringTokenizer st;
        int count = 0;

        for(String rec : record){
            st = new StringTokenizer(rec);
            String command = st.nextToken();

            if("Enter".equals(command) || "Change".equals(command)){ // 입장 or 닉네임 변경   
                String uid = st.nextToken();
                String nickName = st.nextToken();
                users.put(uid, nickName);
            }
            if("Enter".equals(command) || "Leave".equals(command)){ // 입장 or 퇴장
                count++;
            }
        }

        // 정답 배열 만들기
        String[] answer = new String[count];
        int idx = 0;
        for(String rec : record){
            st = new StringTokenizer(rec);
            String command = st.nextToken();
            String uid = st.nextToken();

            if("Enter".equals(command)){
                answer[idx++] = users.get(uid) + "님이 들어왔습니다.";
            } else if("Leave".equals(command)){
                answer[idx++] = users.get(uid) + "님이 나갔습니다.";
            }
        }

        return answer;
    }
}
