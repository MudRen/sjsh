// Room: /d/mojie/chang.c
inherit ROOM;

void create()
{
  set ("short", "�𷨳�");
  set ("long", @LONG
ħ���𷨳��������쵱������ٷ��Ÿ�ɮ����֮�أ���˵����Բ�ţ�
�ڷ��ŵ�������ħ��ն����ħ��������ˮ֮�������ٷ��ŵ��ӻ�
����������������㱻�����֮Ϊ�𷨳����Դ�������������֮��
�𣬴˵ر��Ϊ���Ž��ء���������ͱ���ˮ���ơ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guodao.c",
  "west" : __DIR__"yuan",
  "east" : __DIR__"yuan",
]));
        set("objects", 
        ([ //sizeof() == 1
                "/d/mojie/npc/bing" : 4,
        ]));
  setup();
  call_other("/obj/board/mojie_b", "???");
}
