#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void create ()
{
set ("short", "������");
set ("long", @LONG
 
����һ�����ϵĳǱ�������ȫ����ѩ�����ǡ���ߵĺ���
��������Ű�š��ڳǱ��м���һ�����εı��������и�
�����εĿף�������ԷŽ�ʲô������

LONG);
  set("exits", ([ /* sizeof() == 1 */
    "southeast" : "/u/repoo/mofamen/cl_door",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chilong" : 1,
  ]));
  create_door("southeast", "�����ǳ���", "northwest", DOOR_CLOSED);
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("do_insert", "insert");
        set("no_clean_up", 1);
}

int do_insert(string arg)
{
        object hlcity, ob, me;
        me=this_player();

   if(!me->query_temp("chilong_killed"))
                 return notify_fail("�������ɱ���سǻ�����\n");
        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");

if( !arg || arg!="fang jing" || !(ob=present(arg, me)))
                return notify_fail("�ƺ����зŲ������������\n");

          if( !(hlcity = find_object(__DIR__"hl_door")) )
                hlcity = load_object(__DIR__"hl_door");

        if( hlcity = find_object(__DIR__"hl_door") ) 
        {
                set("exits/enter", __DIR__"hl_door");
                message_vision("$N��$n���뷽�ף�һ���ڹ�����������һ��ͨ����\n", me, ob);
                message("vision", "ͨ����������ˡ���\n", hlcity );
                 hlcity->set("exits/out", __DIR__"clcity");
                destruct(ob);
        call_out("close_down", 600);
        }
        return 1;
}
void close_down()
{
        object hlcity;

        message("vision", "ͨ����ʧ�ں���С�\n", this_object() );
        if( hlcity= find_object(__DIR__"hl_door")) {
        message("vision", "ͨ����ʧ�ں���С�\n", hlcity);
        hlcity->delete("exits/out");
        }
        delete("exits/enter");
}
