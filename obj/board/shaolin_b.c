// shaolin_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���ɱ�", ({ "board" }) );
        set("location", "/d/shaolin/gate.c");
        set("board_id", "shaolin_b");
        set("long", "����һ��ʯ����������������ؼ��������µ���������ս����\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
