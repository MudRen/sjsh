inherit ROOM;
void create ()
{
  set ("short","����");
  set ("long", @LONG

һ�������ķ��䣬����Ĵ���(men)�����عر��ţ��������ƿ������߲�
������ġ����������վ��һ��ʮ���������,�������䲻��������Ǳ�
һ��������Լ��޷�����ס������ɱ����
LONG);
   set("exits", ([      
  ]));
   set("objects", ([ 
      __DIR__"npc/mingshen" : 1,
       ]));
  set("no_magic", 1);
  set("no_quit", 1);
  setup();
}

void init()
{
  add_action("do_push", "push");
}

int do_push(string arg)
{
  object me=this_player();

  int delay;
  if ((arg != "men" && arg != "��") || !arg)
  return notify_fail("��Ҫ��ʲô��\n");
  if (me->is_busy()) return notify_fail("��æ���أ�\n");
  if (me->query_temp("no_move")) return notify_fail("�㱻��ס�ˣ�ʲôҲ�ɲ��ˡ�\n");

  message_vision("\n$N�þ�ȫ�������������ţ�ֻ��һ�������������󣬴��ŵ���
�����ش��ˣ��Լ�ȴ�۵ö������á�\n", me);
  delay=7;
  me->start_busy(delay);
  me->start_call_out( (: call_other, __FILE__, "delay_effect", me, delay:), delay);
  return 1;
}

void delay_effect(object me,int power)
{
        mapping action;
        mapping new_act=([]);
         message_vision("\n$N���˲������Ͻ����������ڣ�ʯ���漴�ֺ����ˡ�\n\n", me);
        me->move(__DIR__"zhanjiandating");
}
