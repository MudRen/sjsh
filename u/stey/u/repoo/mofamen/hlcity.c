//By Repoo
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void create ()
{
set ("short", HIB"������"NOR);
set ("long", @LONG
 
����һ�����ϵĳǱ����Ǳ���Χ�����ȵ��ҽ���Χ������
�ȵ����㴭������������������һ���ǳ�С������ɽ����
���Ƿǳ�������Բ�Ρ�

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/u/repoo/mofamen/hl_door",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/heilong" : 1,
  ]));
  create_door("west", "�����ǳ���", "east", DOOR_CLOSED);
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

   if(!me->query_temp("heilong_killed"))
              return notify_fail("�������ɱ���سǻ�����\n");
        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");

if( !arg || arg!="yuan yu" || !(ob=present(arg, me)))
                return notify_fail("�ƺ����зŲ������������\n");

          if( !(hlcity = find_object(__DIR__"gl_door")) )
                hlcity = load_object(__DIR__"gl_door");

       if( hlcity = find_object(__DIR__"gl_door") ) 
        {
                set("exits/enter", __DIR__"gl_door");
message_vision("$N��$n����Բ�ף�һ���׹�����������һ��ͨ����\n", me, ob);
               message("vision", "ͨ����������ˡ���\n", hlcity );
                  hlcity->set("exits/out", __DIR__"hlcity");
                destruct(ob);
        call_out("close_down", 600);
        }
        return 1;
}
void close_down()
{
        object hlcity;

        message("vision", "ͨ����ʧ�ڰ׹��С�\n", this_object() );
        if( hlcity= find_object(__DIR__"gl_door")) {
         message("vision", "ͨ����ʧ�ڰ׹��С�\n", hlcity);
        hlcity->delete("exits/out");
        }
        delete("exits/enter");
}
