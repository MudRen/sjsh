
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
       set_name("��������԰�", ({ "board" }) );
           set("location", "/d/wiz/entrance");
             set("board_id", "xlqy_ah");
          set("long",     "���ǹ���ʦ����һ��ཻ������ͬ�ٽ������񻰷�չ�����۰塣\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
