// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;
#include <ansi.h>

void create ()
{
    set ("short",HIR "��" HIB "�㺮��" HIR "��" NOR);
  set ("long", @LONG

   �������޳������򸾵����ң���Ȼ͸��һ�ɺ�������ȴ��������ܰ�����ۡ�
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "˯���õĴ���(gosleep,gobed,bed)�� 
",
]));
  set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"workroom",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
          me->move(__DIR__"bed_yudian");
            message_vision(HIY "\nɴ������һ����$N���˽�����\n" NOR, me);
                return 1;
}

