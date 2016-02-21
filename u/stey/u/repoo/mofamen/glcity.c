#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void create ()
{
set ("short", HIW"������"NOR);
set ("long", @LONG
 
����һ�����ϵĳǱ����Ǳ����������ι�״�İ׹ǣ�ʱ
��ʱ��ð�������׻���ɭɭ�ģ������˹��졣��������
��һ�����м�Ҳ��һ����־�͵Ľ���������ͼ�ڡ�������
һ���������εĿס�

LONG);
  set("exits", ([ /* sizeof() == 1 */
    "northeast" : "/u/repoo/mofamen/gl_door",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gulong" : 1,
  ]));
    create_door("northeast", "�����ǳ���", "southwest", DOOR_CLOSED);
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
         object glcity, ob, me;
        me=this_player();
   if(!me->query_temp("gulong_killed"))
              return notify_fail("�������ɱ���سǻ�����\n");
        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");
 if( !arg || arg!="liubian manao" || !(ob=present(arg, me)))
                return notify_fail("�ƺ����зŲ������������\n");

           if( !(glcity = find_object(__DIR__"shendian_door")) )
                glcity = load_object(__DIR__"shendian_door");
       if( glcity = find_object(__DIR__"shendian_door") ) 
{
                set("exits/enter", __DIR__"shendian_door");
message_vision("$N��$n���������εĿף�һ���ʹ�����������һ��ͨ����\n", me, ob);
               message("vision", "ͨ����������ˡ���\n", glcity );
                  glcity->set("exits/out", __DIR__"glcity");
                destruct(ob);
        call_out("close_down", 600);
        }
        return 1;
}
void close_down()
{
        object glcity;
        message("vision", "ͨ����ʧ�ڲʹ��С�\n", this_object() );
        if( glcity= find_object(__DIR__"shendian_door")) {
         message("vision", "ͨ����ʧ�ڲʹ��С�\n", glcity);
        glcity->delete("exits/out");
        }
        delete("exits/enter");
}
