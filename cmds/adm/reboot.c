//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string wiz_status;
   object npc;

   if( me != this_player(1) ) return 0;
   
   wiz_status = SECURITY_D->get_status(me);
   if( wiz_status != "(admin)")
     return notify_fail("ֻ��(admin)Ȩ���߲�����������" + MUD_NAME + "\n");

   seteuid(getuid());

   npc = new(NPC_DEMOGORGON);
   npc->move(START_ROOM);
   npc->start_shutdown();

   write("Ok��\n");

   return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: reboot
 
��������Ϸ, ϵͳ�Ὺʼ������ʱ, ʮ����Ӻ������𶯡�
 
HELP
);
        return 1;
}
 
