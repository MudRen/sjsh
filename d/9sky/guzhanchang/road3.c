//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "����������ڴ�");
  set ("long", @LONG

������Ǵ�˵�еĵ������������ˡ�
����㲻Ը�������Ļ��������뿪�����ļ���
 ==============================
      / \| O   O |
      \ /  \v_'/
       #   _| |_
      (#) (     )
       #\//|* *|\\     ��
       #\/(  *  )/     ��
       #   =====       ��
       #   (\ /)       ��
       #   || ||        ��
      .#---'| |----.
       #----' -----'
===============================
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "north": __DIR__"tian3",
]));
set("objects", ([
     "/d/9sky/guzhanchang/npc/shouhuzhe3": 1]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();


}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "north") {
                if(objectp(a=present("shouhuzhe", environment(me))) && living(a) )
                return notify_fail("�ػ��ߺ���Ը�����ȥ��\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}

