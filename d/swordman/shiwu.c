// Room: /d/qujing/wudidong/south
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

һ��СС��ʯ�ݡ�Сʯ�ݵ�ʯ�ţ�shimen)�����ţ���������
ʯ�ſ����޷��������ڵġ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"xiaolu4",
]));
  setup();
}
void init()
{
  add_action("do_push", "push");
}
int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "shimen" && arg != "ʯ��") || !arg)
    return notify_fail("��Ҫ��ʲô��\n");
  if (me->is_busy()) return notify_fail("��æ���أ�\n");
  if (me->query_temp("no_move")) return notify_fail("�㱻��ס�ˣ�ʲôҲ�ɲ��ˡ�\n");
  if (me->query_str()<40||myeffstr<20)
    {
      message_vision("$N������������ʯ����ȥ�����Ѿ���ţ����֮����Ҳ�����÷ֺ���\n", me);
      return 1;
    }
  if(random(diff)>4)
    {
      message_vision("$N������������ʯ����ȥ��������ʯ�����˫�ַ��顣\n", me);
      percentage=diff*2;
      me->receive_wound("kee", mymaxkee*percentage/100);
      return 1;
    }
  message_vision("$N�����ƶ�ʯ�ţ�ֻ��һ��������������ʯ�Ż����ش��ˡ�\n", me);
  message_vision("$N�Ͽ��������ڣ�ʯ���漴�ֺ����ˡ�\n", me);
  me->move(__DIR__"wunei");
  return 1;
}
