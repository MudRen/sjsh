// shushan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ɽ���԰�", ({ "board" }) );
        set("location", "/d/shushan/square.c");
        set("board_id", "shushan_b");
        set("long",     "��ɽ���԰塣\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}
