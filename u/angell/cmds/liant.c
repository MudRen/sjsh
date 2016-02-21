#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object where = environment(me);
        string skillname;
        int skill, skill_basic,times,i;
        
        seteuid(getuid());

        if(!stringp(arg))
           {
            return notify_fail("ָ���������\n");
           } 
        sscanf(arg,"%s %d",arg,times);   

          if(times>30)
                return notify_fail("��Ҳ̫̰�ˣ������30�Σ�\n");

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if( !arg ) return (__DIR__"enable")->main(me, arg);

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
                return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
        if( skill_basic < 1 )
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
        if( skill_basic/2 <= skill/3 )
                return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        notify_fail("�����ڲ�����ϰ����ܡ�\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

        
        if(times<1)times=1;
        notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
        for(i=0;i<times;i++)
           {
               if( SKILL_D(skillname)->practice_skill(me) ) {
                me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
                  write( HIG "�㿪ʼר�����µ���ϰ" + to_chinese(skillname) + "����ܣ�\n" NOR);
                }
               else return 0;
           }
        return 1;  
}               


int help(object me)
{
        write(@TEXT
  ָ���ʽ��practice|lian <��������> <��ϰ����>

���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�

�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
        );
        return 1;
}
