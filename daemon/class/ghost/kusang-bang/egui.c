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
HIY "$n�������Ŀ������µİ���,һ�������ı��顣$n����һ�������صĳ���һ��.\n",
 HIY "$n��ǰ���������������������еİ���һ������.$N��$n�����ʱ��һ���ƹ�����$n���Դ�.\n",
  });
  string *missone = ({
BLU "$n���з���,���ƾͼƵ�©��һ������,����$N����֮ʱ,�����˲�,��$N�߼���.$N��������,ֻ��������,��һ�б�$n��������.\n",
BLU "$n������Ц:���С��,Ҳ��������Ū,�����ǹع���ǰˣ��!������ô��ʰ��!\n",
  });
  string *hittwo = ({
   HIW "$n����$N,�·���ǰ�����������������ݿֲ����������͡�$n��ʱ�е����ε�ѹ����������!\n",
  HIW "$n��æ����������ͷ��,$N����һ��,һ��Ҹ��͵�ң�һ������$n������.$nһ������,���ˤ��!\n",
  });
  string *misstwo = ({
CYN "ԭ��$n�����մ�,�ջ�$N,�ȵ�$N������,$n���һ��:������!ת������$N!\n",
CYN "$nͻȻһ������,��Ȼ����$N����,$Nһ��ãȻ,��֪��������ʲô����!\n",
  });
  string *hitthree = ({
  HIR "$n��ֿ־�Ŀ�����ǰ�Ĺ�Ӱ����֪�������Ƿ�����ʲô���顣ͻȻӰ����һ�������Ĺ�Ӱ�������,$n��һ����������!\n",
  });
  string *missthree = ({
HIG "˵ʱ��,��ʱ��.$n�������еı�������һ��,ƹ��һ��,��ס��$N�������İ���!\n",
HIG "$n��Цһ��:��Ҳ̫С������!\n",
  });
  string *hit=({
      HIW "$N�����ȵ���$n������ڵ���,����ȥ��������˵�Ų��ݷ�˵����ǰ�ʹ�\n"NOR,
     HIW "��һ����ʵ����,$n����Ӧ��û�����ü��ͱ�$N�ػ�һ��,����ѿ�һ������Ŀ��ӣ�¶���˰�ɭɭ�Ĺ�ͷ,��������!\n"NOR,
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
     if((string)me->query_skill_mapped("force")!="tonsillit")
      return notify_fail("perfrom egui������gouhunshuΪ���ӡ�\n");
        if(me->query_skill("gouhunshu",1) < 150)
      return notify_fail("���gouhunshu����150�����޷�ʹ��perform egui��\n");
     if(me->query_skill("kusang-bang",1)<150)
       return notify_fail("���kusang-bang����ⲻ�����޷�һ���ǳɵ�ʹ����\n");
  if(me->query("max_force") < 1000 || me->query("force")<500)
     return notify_fail("����������㣬����ʹ����ô�����������\n");
 targetexp=(int)target->query("combat_exp")/5000+(int)target->query("daoxing")/5000;
  targetlev=(int)target->query_skill("parry")/2+(int)target->query_skill("dodge");
targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
my=mystr+mylev+myexp;
him=targetstr+targetlev+targetexp;
   msg = CYN "$Nһ�����ȣ��������ţ�\n\nֻ��һ������Ӱ�����׻�ӭ���˳������еİ���ֱ��$n���ţ�\n" NOR;
if( random(my) > him*3/4)
    {
      msg += hitone[random(sizeof(hitone))];
      success+=1;
if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=missone[random(sizeof(missone))];
    msg+=CYN"\n$N�������ͣ��ֺ�û�и��������»��ֵ���ء���ʽ�ݶ��ޱȣ������м�$n�Ѳ�֪����\n"NOR;
 if( random(my+him) > him)
    {
      msg += hittwo[random(sizeof(hittwo))];
      success+=1;
     if(random(mystr+targetstr)>targetstr) hurt+=1;
   damage=50+random(mystr/5);
    }
  else msg+=misstwo[random(sizeof(misstwo))];
    msg+=CYN"\n$N�������ݣ����ٹ��أ������ڰ��еĹ�꣬����ɭɭ��ɱ��������$n��Χ��\n"NOR;
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
