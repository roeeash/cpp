from main import run_stats

def italy(count1,weights,total_count,counter,c):
    rate1 = run_stats(16756, 16908, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16950, 16952, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16954, 17106, total_count, counter, c)
    count1 += 1


    count2 = 0
    #italy_season2
    rate2 = run_stats(18582, 18726, total_count, counter, {key:value*0.75 for key,value in c.items()})
    count2 += 1
    # average precision over intervals
    weights.append((rate1 / count1) * (1/2) + (rate2 / count2)*(1/2))

def germany(count1,weights,total_count,counter,c):
    rate1 = run_stats(17516, 17750, total_count, counter, c)
    count1 += 1
    rate1 = run_stats(17754, 17780, total_count, counter, c)
    count1 += 1

    count2 = 0
    # germny_season2
    rate2 = run_stats(19342, 19469, total_count, counter, {key: value * 0.75 for key, value in c.items()})
    count2 += 1
    # average precision over intervals
    weights.append((rate1 / count1) * (1 / 2) + (rate2 / count2) * (1 / 2))

def england(count1,weights,total_count,counter,c):
    rate1 = run_stats(16376, 16498, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16500, 16527, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16529, 16545, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16548, 16557, total_count,counter, c)
    count1 += 1
    rate1 += run_stats(16559, 16570, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16572, 16581, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16583, 16591, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16600, 16617, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16620, 16639, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(16641, 16670, total_count,counter, c)
    count1 += 1
    rate1 += run_stats(16675, 16680, total_count, counter, c)
    count1 += 1

    # england season 2
    count2 = 0
    rate2 = 0

    c = {key: value * 0.25 for key, value in c.items()}
    rate2 += run_stats(18202, 18261, total_count, counter, c)
    count2 += 1
    rate2 += run_stats(18272, 18275, total_count, counter, c)
    count2 += 1
    rate2 += run_stats(18340, 18361, total_count, counter, c)
    count2 += 1
 # average precision over intervals
    weights.append((rate1 / count1) * (1 / 2) + (rate2 / count2) * (1 / 2))





def france(count1,weights,total_count,counter,c):
    rate1 = run_stats(17822, 17850, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(17852, 17883, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(17919, 17954, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(17956, 18002, total_count, counter, c)
    count1 += 1
    rate1 += run_stats(18004, 18173, total_count, counter, c)
    count1 += 1


    count2 = 0
    #france_season2
    rate2 = run_stats(19648, 19788, total_count, counter, {key:value*0.75 for key,value in c.items()})
    count2 += 1
    # average precision over intervals
    weights.append((rate1 / count1) * (1/2) + (rate2 / count2)*(1/2))


def spain(count1,weights,total_count,counter,c):
  rate1 = run_stats(17136, 17173, total_count, counter, c)
  count1 += 1
  rate1 += run_stats(17178, 17232, total_count, counter, c)
  count1 += 1
  rate1 += run_stats(17240, 17336, total_count, counter, c)
  count1 += 1
  rate1 += run_stats(17342, 17493, total_count, counter, c)
  count1 += 1

  count2 = 0
  # france_season2
  rate2 = run_stats(18962, 19106, total_count, counter, {key: value * 0.75 for key, value in c.items()})
  count2 += 1
  # average precision over intervals
  weights.append((rate1 / count1) * (1 / 2) + (rate2 / count2) * (1 / 2))