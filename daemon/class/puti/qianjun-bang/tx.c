//̸Ц�����  wosshipg
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me, object target)
{
string msg,targetrude;
int my,him;
  int success,hurt,diff,damage;
   int myexp=(int)me->query("combat_exp")/5000+(int)me->query("daoxing")/5000;
  int mylev=(int)me->query_skill("stick")/2+ (int)me->query_skill("qianjun-bang");
  int mystr=(int)me->query("str")+(int)(me->query_skill("unarmed")/10-2);
  int targetlev, targetstr,targetkar,targetexp,targeteffkee;
  string *hitone = ({
HIY "$n��æ�����еı�����,����$N����ʽ̫ͻȻ��,$n����һ��,����������صĳ���һ��.\n",
HIY "$n������û���뵽��ôƽ�������һ�о�Ȼ����˾޴������.$Nһ�����صĴ���$n���ұ�.\n",
  });
  string *missone = ({
BLU "$n���з���,���ƾͼƵ�©��һ������,����$N����֮ʱ,�����˲�,��$N�߼���.$N��������,ֻ��������,��һ�б�$n��������.\n",
BLU "$n������Ц:���С��,Ҳ��������Ū,�����ǹع���ǰˣ��!������ô��ʰ��!\n",
  });
  string *hittwo = ({
 HIW "$n���޻���֮��,�������Ŀ��ű�$N��ͷһ��,$n��ʱѪ������,��״�������!\n",
 HIW "$n��֪Ҫ�Կ���,��æ����������ͷ��֮��,$N�����ֿ�,����һ��,һ������$n������.$nһ������,��Щˤ��!\n",
  });
  string *misstwo = ({
CYN "ԭ��$n�����մ�,�ջ�$N,�ȵ�$N������,$n���һ��:������!ת������$N!\n",
CYN "$nͻȻһ������,��Ȼ����$N����,$Nһ��ãȻ,��֪��������ʲô����!\n",
  });
  string *hitthree = ({
HIR "$n��һ��:����!���ֻ�û��˵����,��$Nһ�����ڱ���,$nʹ�಻��,�۵�һ�����һ����Ѫ.�������Ʋ���!\n",
HIR "$N��һ��:����������!�����еİ�������һ�Ų���,��ͷ�����Ĵ��˹���.$n����������,�ֳ������ص�һ��!\n",
  });
  string *missthree = ({
HIG "˵ʱ��,��ʱ��.$n�������еı�������һ��,ƹ��һ��,��ס��$N�������İ���!\n",
HIG "$n��Цһ��:��Ҳ̫С������!\n",
  });
  string *hit=({
     HIW "$N������������ë��,������ǰ��Ū?��\n"NOR,
     HIW "��һ����ʵ����,$n����Ӧ��û�����ü��ͱ�$N�ػ�һ��,�ֱ��ں�,��������!\n"NOR,
  });
  string *miss;
  
  if( !target ) target = offensive_target(me);
  if( !target
     ||      !target->is_character()
     ||      !me->is_fighting(target) )
    return notify_fail("ǧ�����������źÿ��ģ�ֻ�ܶ�ս������ʩ�á�\n");
  targetrude=RANK_D->query_self_rude(target);
  miss=({
 BLU"$n������Ц����"+targetrude+"��˵��ǧ�����ж�������������һ����Ҳ��������\n"NOR,
    BLU"$n��Цһ������$N��м��˵��������㱾�£�"+targetrude+"��û�������\n"NOR,
    BLU"$n�����Ц��������ʲô���£������ó����ɣ�\n"NOR,
  });
  if((string)me->query_skill_mapped("force")!="wuxiangforce")
     return notify_fail("̸Ц�����������wuxiangforceΪ���ӡ�\n");
      if(me->query_skill("wuxiangforce",1) < 150)
     return notify_fail("����ڹ����Ӳ��㣬�޷�ʹ��̸Ц�������\n");
   if(me->query_skill("qianjun-bang",1)<150)
     return notify_fail("���ǧ��������ⲻ�����޷�һ���ǳɵ�ʹ����\n");
  if(me->query("max_force") < 1000 || me->query("force")<500)
     return notify_fail("����������㣬����ʹ����ô�����������\n");
 targetexp=(int)target->query("combat_exp")/5000+(int)target->query("daoxing")/5000;
  targetlev=(int)target->query_skill("parry")/2+(int)target->query_skill("dodge");
targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
my=mystr+mylev+myexp;
him=targetstr+targetlev+targetexp;
 msg = CYN "$Nһ�����ȣ�ӭ��������������һ���ǳɣ�\n\nֻ��һ����Ӱ���������еİ���ֱ��$n���ţ�\n" NOR;
if( random(my) > him*3/4)
    {
      msg += hitone[random(sizeof(hitone))];
      success+=1;
if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=missone[random(sizeof(missone))];
   msg+=CYN"\n$N�ƺ�ʲô��û�п���,ȫȻ������ǰ��Σ��,��$n���Ŀ�����ʱ��ŭ��һ��,�Ӱ����$n�����˸����ֲ�����\n"NOR;
 if( random(my+him) > him)
    {
      msg += hittwo[random(sizeof(hittwo))];
      success+=1;
     if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=misstwo[random(sizeof(misstwo))];
   msg+=CYN"\n$N����$n��������ô���µ�ʱ��,����Ѹ���ޱȵ�һ��!\n"NOR;
    if(random(my+him)>(him/2))
    {
      msg+=hitthree[random(sizeof(hitthree))];
      success+=1;
     if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=missthree[random(sizeof(missthree))];
  diff=3-success;
  if (diff<0) diff = 0;
  if (success) hurt=damage*hurt/success;
  else hurt=0;
  me->add("force", -(150*success+70*diff));
  targeteffkee=(int)target->query("eff_kee");
  target->receive_wound("kee", targeteffkee*hurt/100);
  target->receive_damage("kee", target->query("kee")*(damage-hurt)/100);
  if(success)
    {
me->start_busy(1+random(4-(mystr)/50));
   target->start_busy(3+random(4-(mystr)/50));
  target->add("force",-200);
      msg+=hit[random(sizeof(hit))];
    }
  else
    {
me->start_busy(1+random(4-(mystr)/50));
      msg+=miss[random(sizeof(miss))];
    }
  message_vision(msg, me, target);
  return 1;
}
