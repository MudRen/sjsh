#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���¾�¥");
  set ("long", @LONG

����������������Ͼ�¥��,����ľ���Ʈ����
���������õ�ʵ����û��˵��.���й�������
���һʮ����,���3��...��¥��ľƾ�˵�Ǵ�
��Զ�ı���������� ... ...
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
    "east" : "/u/calvin/����/����/������8",
       "up" : "/u/calvin/room/���¾�¥2",    
]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/obj/����/������" : 1,
        ]));

  setup();
}
