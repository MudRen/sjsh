inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "������");
  set ("long", @LONG

    �������������̫��ס������Ȼ�����˾���֮�ϡ���������а���Ʈ
�����ıڹ������������������״������û����ҹ֮�֣�ֻ�п����в�ʱ
�����������㣬���˸е�ƽ�����������������ʵĻ������棬����һ����
�Թ����ķǳ�Ŭ������ϸ��ȥ�����ߵ�ǽ������һ������ (duilian)��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "duilian" : HIC" �� �� �� �� Զ���� �� �� �� ־��"NOR,
]));  
  set("no_time",1);
  set("valid_startroom", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "kz" : "/d/city/kezhan",
]));

  setup();
}
