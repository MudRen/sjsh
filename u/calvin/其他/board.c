//lanling_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIR"�����ʾ��"NOR, ({ "board" }) );
        set("location", "/d/lanling/�������");
       set("board_id", "lanling_board");
        set("long",
                "����һ�������,��ר��Ϊ��Щϲ����������ī�ʵ����ṩ��.�����(post)��\n" );
        setup();
        set("capacity", 150);
        replace_program(BULLETIN_BOARD);
}
