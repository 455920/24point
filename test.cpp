class Solution {
public:
    
    //�ж��ǲ��ǵ���24
    bool equal(double n1)
    {
        return n1-24>-EXP&&n1-24<EXP;
    }
    //����
    //����Ҫ�ж������ǲ���Ϊ0
    //��ʹ��ȫ�������������������
    //�����ʹ�÷����㷨
    bool fun(vector<double>& nums,double value,int i)
    {
        if(i==4)
        {
            return equal(value);
        }
        //�ӷ��ͳ˷�����Ҫע��ǰ��˳��
         if(fun(nums,value+nums[i],i+1)||fun(nums,value-nums[i],i+1)||fun(nums,value*nums[i],i+1)||fun(nums,value/nums[i],i+1))
             return true;
        
        //�����ͳ���Ҫ�ж�ǰ��ѭ��
        if(value!=0&&fun(nums,nums[i]/value,i+1))   
             return true;
        
       if(fun(nums,nums[i]-value,i+1))
                return true;
        
        .
            
        
        //���������ŵ����
        if(i==2)
        {
            if(fun2(value,nums[2]+nums[3])
               ||fun2(value,nums[2]-nums[3])
                 ||    fun2(value,nums[2]*nums[3])
                   ||      fun2(value,nums[2]/nums[3])
                      ||       fun2(value,nums[3]/nums[2])
                        ||       fun2(value,nums[3]-nums[2]))
                return true;
        }
        
        return false;
    }
    
    bool fun2(double num1,double num2)
    {
    if(equal(num1*num2)
      ||equal(num1-num2)
      ||equal(num2-num1)
      ||equal(num1+num2))
        return true;
        if(num1!=0&&equal(num2/num1))
        {
            return true;
        }
        if(num2!=0&&equal(num1/num2))
            return true;
        
        return false;
    }
    
    
    
    
    
    bool judgePoint24(vector<int>& nums) {
        //����ȫ����
        vector<double> s(4);
        for(int i=1;i<=4;i++)
        {
            for(int j =1 ;j<=4;j++)
            {
                 for(int w =1 ;w<=4;w++)
                 {
                      for(int o =1 ;o<=4;o++)
                      {
                        if(i*j*w*o==24&&i+j+w+o==10)
                        {
                           
                            s[0]=nums[i-1];
                            s[1]=nums[j-1];
                            s[2]=nums[w-1];
                            s[3]=nums[o-1];
                           if (fun(s,s[0],1))
                               return true;
                        }
                      }
                 }
            }
        }
        return false;
    }
};
