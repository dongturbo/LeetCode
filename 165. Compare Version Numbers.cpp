int compareVersion(string version1, string version2) {
    int ver1 = 0, ver2 = 0, i1 = 0, i2 = 0;
	while (i1 < version1.length() || i2 < version2.length()){
		while (i1<version1.length() && version1[i1] != '.'){
			ver1 = ver1 * 10 + (version1[i1] - '0');
			i1++;
		}
		while (i2 < version2.length() && version2[i2] != '.'){
			ver2 = ver2 * 10 + (version2[i2] - '0');
			i2++;
		}

		if (ver1 > ver2)
			return 1;
		else if (ver2>ver1)
			return -1;
		ver1 = 0;
		ver2 = 0;
		i1++;
		i2++;
	}
	return 0;
}
