// nancheng_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"������"HIR"����"HIC"���۰�"NOR, ({ "board" }) );
        set("location", "/d/wiz/menpai_room");
        set("board_id", "menpai_b");
        set("long",     HIC"����һ������ʦ���������ɷ�չ�����õ����Ű塣\n"NOR );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
