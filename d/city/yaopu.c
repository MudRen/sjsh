//changan city

#include <room.h>
#include <ansi.h>
inherit SELLYAO;
void create ()
{
        set ("short","�ش�ҩ��" );
        set ("long", @LONG

���ǳ�����һ�����ֺŵ�ҩ�̣��ഫԭ�����ϰ��ǻʹ��е���ҽ����
�ο�֪һ�����ſڹ���һ������ (paizi)��ҩ���еİ���Ҳʮ�ֿ�����
���α��ڿ�Ļ�Ʋ��ĸɸɾ�����ǽ�Ϲ����˱���������л�ҡ�
LONG);
        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"zhuque-s2",
                "east" : __DIR__"jishitang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yang" : 1,
        ]));

set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
�����а�����ʷ�������á����չ����¸�����ҩ
�͹ٿ��������
    ������������������������������
    ��	��ҩ(sell)		��
    ��	��ҩ(buy) ��list�鿴��	��
    ������������������������������
"]));

  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}


