//֪��ʦү ������(Dongfang wei)

#include <ansi.h>
#include <command.h>
string change_name(object me);
int do_name(string arg,object me);
int accept_object(object me, object ob);

inherit NPC;
void create()
{
        set_name("������",({ "dongfang wei","wei","zhifu","zhi fu" }));
        set("gender", "����" );
        set("per", 30);
        set("age", 63);
    set("title", HIW"֪��ʦү"NOR);
        set("long",
HIC"�����ǳ����������Һ��,��ٸ��������þ�˵һ���������ޱȣ������������֮����\n"NOR);
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("inquiry", ([
            "����": (: change_name :),
            "change_name": (: change_name :),
            "change-name": (: change_name :),
            "��������": (: change_name :),
            "����":  "���ھ�ȱǮ�����ҿ��Ǻ��б��µ���ѽ��",
            "fly":  "����������ã������������һ˧�磬��ϧ��˵Ҫ����������......",
            "��ѩ":  "����������ã������������һ˧�磬��ϧ��˵Ҫ����������......",
            "meokey":  "��ָ�Ǹ�˥���𣿲��Ǳ�����������...(��𣬵���˵�����ڹ���)",
           "����ĸ��":  "��ָ�Ǹ�˥���𣿾�����...(��𣬵���˵�����ڹ���),��"HIR"�߿�"HIB"����"HIW"����"NOR,
           "chuhen":  "��ָ�Ǹ�˥���𣿾�����...(��𣬵���˵�����ڹ���),��"HIR"�߿�"HIB"����"HIW"����"NOR,
            "�����˲�":  "��ָ�Ǹ�˥���𣿲��Ǳ�����������...(��𣬵���˵�����ڹ���)",
            "shenxian":  "����ѽ���������������㲻֪������������������"HIC"��ңɽׯ��ɽ��ʦ"NOR,
            "����":  "����ѽ���������������㲻֪������������������"HIC"��ңɽׯ��ɽ��ʦ"NOR,
            "owen":  "�����Ǹ������𣿺ٺ٣��Ҳ��Ҳ�,�ҲȲȲ�",
            "��":  "�����Ǹ������𣿺ٺ٣��Ҳ��Ҳ�,�ҲȲȲ�",
            "����":  "����ѽ���������������㲻֪����������������ʲô"HIR"����"HIG"��֪�����"NOR,
            "wangp":  "����ѽ���������������㲻֪����������������ʲô"HIR"����"HIG"��֪�����"NOR,
        ]) );
        set("chat_msg",({
            "֪���ᷳ˵��:����������\n",
        }));
        setup();
}

void init()
{
        object ob,me;
        add_action("do_name","name");
}

int accept_object(object me, object ob)
{
       int i,p;
                 i=(int)me->query("marks/name_times");
        p=i*i;
    if ( !me->query_temp("marks/ask_change"))
              {
      command("?");
            return notify_fail(HIB"����Ǯ����?�ٺ٣���\n"NOR);
           }
        if( ob->query("money_id") && ob->value() >= (p*1000000+1000000))
        {
        command("nod");
        command("say �ðɣ�"+me->query("name")+"�������("HIR" name xxx "HIG"),���޸����������\n"NOR);
       me->delete_temp("marks/ask_change");
        me->set_temp("marks/change_name",1);
        return 1;
        }
       else {
        command("heng");
        command("say �ٺ٣�"+me->query("name")+"�㵹�󵨣���Ϸˣ��֪����\n");
        return 1;
        }
}
int do_name(string arg,object me)
{
        string *banned_name = ({
                "��", "��", "��", "��", "��", "��", "��", "��", "��",
                "��","��", "��ʧ����", "����",
                "��ѩ", "����", "�����˲�", "����", "����",
        });
        int i;
        me = this_player();
        if(!(int)me->query_temp("marks/change_name"))
        {
            return notify_fail("֪���ٺ���Ц��:���²��ɣ�\n");
        }
        if( !arg ) return notify_fail("֪��Ц�����а��֣���������������������\n");
        if( strlen(arg) > 12 )
        return notify_fail("֪�����������ţ�����������������˻����ҷ��ˣ�������ô�������֣���\n");
        if( strlen(arg) < 2 )
        return notify_fail("֪�����������ţ�����������������˻����ҷ��ˣ���ô��Ҳ�����֣�����\n");
        while(i--) {
                if( arg[i]<=' ' ) {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( (strsrch(arg, "��") >= 0) ||
                    (strsrch(arg, "��") >= 0)) {
                        write("�Բ�������������ֲ������������ĵ��֡�\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) {
                       write("�����Ҳ���Ӣ�ĵģ������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }
        if( member_array(arg, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }
        if( (strlen(arg) < 2) || (strlen(arg) > 12 ) ) {
                write("�Բ�������������ֱ����� 1 �� 6 �������֡�\n");
                return 0;
        }

        me->delete_temp("marks/change_name");
        me->add("marks/name_times",1);
    write(WHT"�ܺã���ɹ����޸������֡�Ŀǰ���Ѿ��޸���"+(int)me->query("marks/name_times")+"�����֡�\n"NOR);
        if (me->query("gender")=="Ů��")
        message_vision(HIW"֪���������ߣ������󷽣����͸���$N�ķ�����"NOR+HIR"�úã����˾͸��˰�...\n"NOR,me);
        else
        message_vision(HIW"֪���ֹ�һ����..ʲô����..��ȴ���Ǹ���$N�Ĵ�����"NOR+HIR"�úã����˾͸��˰�...\n"NOR,me);
message("channel:chat",HIM+"�������쳯��"NOR+HIW"֪��ʦү"NOR+HIM"(ZhiFu)��"+me->query("name")+HIC"�ָ���Ϊ"NOR+arg+HIC"���ش˵Ǽǡ�\n"+NOR,users());
        me->set("name",arg);

        return 1;
}
string change_name(object me)
{
   int p,i;
  me=this_player();   
 if ( me->query_temp("marks/change_name"))
        {
      command("?");
            return HIC"ǮҲ���ˣ��챨����Ҫ�Ķ������֣��Ҹ��ľ����ˣ�\n"NOR;
         }
    if ( me->query_temp("marks/ask_change"))
        {
      command("?");
            return HIG"�콻"NOR+HIR"Ǯ"NOR+HIG"�����ˣ�����ô������\n"NOR;
        }
    if ( !me->query("marks/name_times",1))
        {
      command("hoho");
      command("say ��һ���ǰ�....����800gold�����ˣ���");
        }
else {
                 i=(int)me->query("marks/name_times");
              p=i*100+800;
        message_vision(HIR"֪������һ��,����θĶ��ҿ�����Ҳ��"NOR+p+HIR" gold����\n"NOR,me);
          }
        me->set_temp("marks/ask_change",1);
        return HIB"��������ҪС��һ�ʲ��ɡ�����"NOR+"��֪��������Ц��������";
}
