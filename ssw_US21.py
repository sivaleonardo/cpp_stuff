
def US21_first_cousins_should_not_marry_anomaly(fam):
    if (fam.husbandObject.childFamilyObject in fam.wifeObject.spouseFamilyObjects) or (fam.wifeObject.childFamilyObject in fam.husbandObject.spouseFamilyObjects):
        fam.anomalies.append("Parents should not marry their children")

def US22_aunts_uncles_should_not_marry_anomaly(fam):
    if fam.husbandObject.childFamilyObject != "" and fam.husbandObject.childFamilyObject == fam.wifeObject.childFamilyObject:
        fam.anomalies.append("Siblings should not marry")


        #for first cousins marrying - can i check to see if they have the same grandparents ? and if they do then the they should not marry 

        #for aunts and uncles marrying the neice and nephews I should check to see if the aunt/uncle are brother or sister to the person they're marrying parents?
        # or check if grandparent is also the other ones parents ?  