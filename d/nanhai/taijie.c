// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "̨��");
  set ("long", @LONG
 
    ���������ǰ������ƽ�е���ʯ̨�ס�̨���Ͼ����ο������룬
���꣬�ɺ׵����ޣ���̬���涯�ˡ�̨�����������������һ�˸ߵ���
ͭ����¯���������ƣ������뵡�
LONG);

  set("outdoors", 1);

  set("exits", ([
  "south" : "/d/nanhai/dadian",
  "northup" : "/d/nanhai/neidian",
]));

  setup();
  replace_program(ROOM);
}

