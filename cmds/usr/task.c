//By angell 2001/5/15

#include <ansi.h>

int main(object me, string str)
{   
     string output;    
     seteuid(getuid(me)); 
     me->add("sen",-20); 
     me->start_busy(2);

    output = HIR"�� "HIW"������"HIR" ��"HIG" ʹ����\n" NOR; 
    output += ""HIW"��������������������������������������������������������������������������\n"NOR"";   
    output += TASK_D->dyn_quest_list();  
    output += ""HIW"��������������������������������������������������������"HIG" ������"HIW" ��������\n\n"NOR""; 
    
     me->start_more(output);   
     return 1;
}

int help(object me)
{  
      write(@HELP

ָ���ʽ: task
���ָ����������֪Ŀǰ������ʹ��.
Ϊ�˼���ϵͳ����������������job������ÿ��һ��Ҫ��20�ľ���

HELP); 
       return 1;
}
