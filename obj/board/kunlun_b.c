// kunlun_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>


void create()
{
        set_name(HIW"����ɽ���"NOR, ({ "board" }) );
        set("location", "/d/kunlun/gate.c");
        set("board_id", "shaolin_b");
        set("long", "����һ��ʯ����������������ؼ�������ɽ���鶴����������ս����\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
