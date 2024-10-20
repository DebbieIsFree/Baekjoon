class Solution {
    public int solution(String skill, String[] skill_trees) {
        int ans = 0;
        
        for(int i=0; i<skill_trees.length; i++){
            String str = skill_trees[i];
            
            int idx = -100;
            boolean flag = false;
            
            for(int j=0; j<skill.length(); j++){
                if(str.indexOf(skill.charAt(j)) == -1){
                    idx = 100;
                }
                else if(str.indexOf(skill.charAt(j)) > idx){
                    idx = str.indexOf(skill.charAt(j));
                }
                else if(str.indexOf(skill.charAt(j)) < idx){
                    flag = true;
                    break;
                }
            }
            if(!flag)
                ans++;
        }
        
        return ans;
    }
}