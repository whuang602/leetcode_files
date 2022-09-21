class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        c1=0
        c2=0
        median=None
        contain=[]
        halfPoint = ceil ( (len(nums1)+len(nums2)) / 2.0)
        
        while (median == None):
            if ( c1 < len(nums1) and c2 < len(nums2) ):
                if (nums1[c1] <= nums2[c2]):
                    contain.append(nums1[c1])
                    c1+=1
                else:
                    contain.append(nums2[c2])
                    c2+=1
            else:
                if (c1 < len(nums1)):
                    contain.append(nums1[c1])
                    c1+=1
                elif (c2 < len(nums2)):
                    contain.append(nums2[c2])
                    c2+=1
                        
            if( len(contain)-1 == halfPoint or halfPoint == 1):
                if (len(nums1)+len(nums2)) % 2:   
                    if (halfPoint == 1 ):
                        median = float(contain[0])
                    else:
                        median = float(contain[-2])
                else:
                    if (halfPoint == 1):
                        if (len(nums1)>1):
                            contain = [nums1[0],nums1[1]]
                        elif (len(nums2) > 1):
                            contain = [nums2[0],nums2[1]]
                        else:
                            contain=[nums1[0],nums2[0]]
                    median = float((contain[-1] + contain[-2]) / 2.0)
    
               
        return median
               