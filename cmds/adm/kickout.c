#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        string msg;
        object ob;
        if( !arg ) return notify_fail("��Ҫ��˭�߳�ȥ?\n");
        ob = find_player(arg);
        if( (string)SECURITY_D->get_status(ob) == "(admin)" ) 
              return notify_fail("�㲻�ܰ������߳�ȥ!\n");
 seteuid(ROOT_UID);
        if ( !ob ) return notify_fail("û����ˡ�\n");
        tell_object(ob, RED "�Լ����ذɢ� \n " NOR );
        destruct(ob);
        if (
 ob ) write("���޷���"+arg+"�߳�ȥ��\n" );
        else  write("���"+arg+"�߳�ȥ��\n" );
        return 1;
}



