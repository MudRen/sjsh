// Room: /d/wiz/menpai_room
inherit ROOM;
#include <ansi.h>;

void create ()
{
  set ("short", "����Ʈ��������������");
  set ("long", 

"�����ǻ�����ʦ����Ʈ�Ĺ����ң���������ʦ�ǿ������۷�չ
�����ɵ����ˣ����۸����ɷ�չƽ��ȸ�������ġ��������ʲô
�õ�������뷨�������Ϊĳ�����Ҳ�������"HIY"�Уϣӣ�"NOR"���������
�塣�һᾡ��������ϵ�ģ�лл��"HIC"������  "HIR"����Ʈ
"HIC"\n����Ʈ�����������������£�

"HIW" �� �� "HIC"�������"HIR"99.9%"HIC"��
\n"NOR
 );

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/city/kezhan",
   "east" : __DIR__"jobroom", 
]));
  set("light_up", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/menpai_b", "???");
}
