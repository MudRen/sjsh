// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>

inherit ROOM;
#include <ansi.h>

void create ()
{
    set ("short",HIG "��԰����" NOR);
  set ("long", @LONG

   ������������ҡ�
һ���紺������͸��ľ����Ͷ�������ڡ��������������Ѿ���ʼ���������ˣ�
�ƺ�����㻽�ѡ�ǽ���������ֻ���ɢ����ī�㣭����������������д�ģ���Ȼ
�ߵ������д�ú��ѿ����������ƺ��ǳ�ϲ����ÿ�춼����������Сʱ��
С���м���һ���ؾ��Ĵ�(bed)��
LONG);

  set("no_fight", 1);
  set("objects",
 ([
 __DIR__"hua.c" : 1,
 __DIR__"obj/zuanjie" : 1,
  "u/rainy/hunsha" : 1,
 
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "˯���õĴ���(gosleep,gobed,bed)�� 
",
]));
  set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"workroom",
           "pig" :  "/u/rainy/workroom",
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
          me->move(__DIR__"bed");
            message_vision(HIY "\nɴ������һ����$N���˽�����\n" NOR, me);
                return 1;
}
