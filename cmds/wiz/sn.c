//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object ob;

   if( !arg ) {
     if( objectp(ob = query_snooping(me)) )
        write("���������ڼ���" + ob->query("name") + "���յ���ѶϢ��\n");
     return 1;
   }
    else if( arg=="none" ) {
     snoop(me);
     write("Ok.\n");
     return 1;
   }
else if(query_snooping(me)) snoop(me);
// else if(query_snooping(me)){
// write("���м�˫���䰡������ snoop none �����ǰ������ \n");
// return 1;
// }

   ob = find_player(arg);
   if(!ob) ob = find_living(arg);
   
   if(!ob) ob = LOGIN_D->find_body(arg);
   /* added by mon. 2/23/97 */

   if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");

   if( wizhood(me) != "(admin)"
   &&   wiz_level(me) <= wiz_level(ob) )
     return notify_fail("��û�м���" + ob->name() + "������ѶϢ��Ȩ����\n");

   if( me==ob ) return notify_fail("���� snoop none ���������\n");
     
   snoop(me, ob);
   write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");

   return 1;
}

int help()
{
   write(@TEXT
ָ���ʽ��snoop <ĳ��>|none

��������ʹ������������ѶϢ��snoop none ��ȡ��������
TEXT
   );
   return 1;
}
