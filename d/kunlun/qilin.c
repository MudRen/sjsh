//kunlun
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

    ��ϼɢ�ʣ�����ҡ�⣻ǧ���ϰأ��������ǧ���ϰأ�������ɽ��ȾȾ���������
����һ��ɫ�Բԡ������滨�������ű��������㣻������Һ���ã������ײݴ�˿����ʱ��
�ɺ�ণ�ÿ������裻�ɺ��ʱ�������������Զ������账��ë����ɫ���ƹ⡣��¹��Գ
ʱ���֣���ʨ�������вأ�ϸ���鸣�أ�����ʤ���á�
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "west" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

